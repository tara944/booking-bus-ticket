#include <stdio.h>
#include <string.h>

char username[10][25];
int password[10];
int usercount = 0;

// Ticket details
char bookedBus[10][25]; // user ke hisab se bus name
int ticketCount[10];    // user ke hisab se ticket number

int loginmenu() {
    int choice;
    printf("\n========= LOGIN MENU ==========\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // clear newline
    return choice;
}

int usermenu() {
    int choice;
    printf("\n======== USER MENU ==========\n");
    printf("1. Book Ticket\n");
    printf("2. Cancel Ticket\n");
    printf("3. Check Bus Status\n");
    printf("4. Logout\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void registration() {
    printf("\nEnter your username: ");
    getchar();
    fgets(username[usercount], sizeof(username[usercount]), stdin);
    username[usercount][strcspn(username[usercount], "\n")] = '\0'; // remove newline

    printf("Enter your password (number only): ");
    scanf("%d", &password[usercount]);
    getchar();

    // initialize ticket info
    strcpy(bookedBus[usercount], "No ticket");
    ticketCount[usercount] = 0;

    printf("Registration successful!\n");
    usercount++;
}

void bookTicket(int userIndex) {
    printf("\nEnter Bus Name: ");
    fgets(bookedBus[userIndex], sizeof(bookedBus[userIndex]), stdin);
    bookedBus[userIndex][strcspn(bookedBus[userIndex], "\n")] = '\0';

    printf("Enter Number of Tickets: ");
    scanf("%d", &ticketCount[userIndex]);
    getchar();

    printf("✅ Ticket booked successfully!\n");
    printf("Bus: %s | Tickets: %d\n", bookedBus[userIndex], ticketCount[userIndex]);
}

void cancelTicket(int userIndex) {
    strcpy(bookedBus[userIndex], "No ticket");
    ticketCount[userIndex] = 0;
    printf("❌ Ticket cancelled successfully!\n");
}

void checkBusStatus(int userIndex) {
    printf("\n===== Your Booking Details =====\n");
    printf("Bus: %s\n", bookedBus[userIndex]);
    printf("Tickets: %d\n", ticketCount[userIndex]);
}

void login_fun() {
    char temp_username[25];
    int temp_password;
    int found = -1;

    printf("\nEnter your username: ");
    getchar();
    fgets(temp_username, sizeof(temp_username), stdin);
    temp_username[strcspn(temp_username, "\n")] = '\0';

    printf("Enter your password: ");
    scanf("%d", &temp_password);
    getchar();

    for (int i = 0; i < usercount; i++) {
        if (strcmp(username[i], temp_username) == 0 && password[i] == temp_password) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("\n✅ Login successful! Welcome %s\n", username[found]);
        int user_choice;
        do {
            user_choice = usermenu();
            switch (user_choice) {
                case 1:
                    bookTicket(found);
                    break;
                case 2:
                    cancelTicket(found);
                    break;
                case 3:
                    checkBusStatus(found);
                    break;
                case 4:
                    printf("Logging out...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while (user_choice != 4);
    } else {
        printf("❌ Wrong username or password!\n");
    }
}

int main() {
    int choice;
    do {
        choice = loginmenu();
        switch (choice) {
            case 1:
                login_fun();
                break;
            case 2:
                registration();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);
    return 0;
}
