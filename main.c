#include "library.h"

int main() {
    User *users = malloc(2 * sizeof(User));
    if (users == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int numUsers = 2;
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "password");
    users[0].tripsTaken = 0;

    strcpy(users[1].username, "trainlover5");
    strcpy(users[1].password, "ilovetrains!");
    users[1].tripsTaken = 0;

    Train trains[ALL_TRAINS];
    int numTrains = 3;
    trains[0] = (Train){101, "Sounder N Line", "Seattle, WA", "Everett, WA", 4, 450, 450, 5.75};
    trains[1] = (Train){102, "Sounder S Line", "Seattle, WA", "Tacoma, WA", 4, 900, 900, 5.75};
    trains[2] = (Train){103, "Coast Starlight", "Seattle, WA", "Los Angeles, WA", 3, 356, 356, 40.0};

    int choice;
    int loggedInUserIndex = -1;

    while (1) {
        if (loggedInUserIndex == -1) {
            loginMenu();
            printf("\nEnter choice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                signUp(&users, &numUsers);
            } else if (choice == 2) {
                char username[50];
                char password[50];
                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);
                loggedInUserIndex = login(users, numUsers, username, password);
                if (loggedInUserIndex == -1) {
                    printf("Invalid credentials. Please try again.\n");
                } else {
                    printf("Login successful. Welcome, %s!\n", username);
                }
            } else if (choice == 3) {
                printf("Exiting...\n");
                free(users);
                break;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else {
            dashboard(users[loggedInUserIndex].username);
            printf("Enter choice: ");
            scanf("%d", &choice);

            if (strcmp(users[loggedInUserIndex].username, "admin") == 0) {
                if (choice == 1) {
                    bookTicket(trains, numTrains, &users[loggedInUserIndex]);
                } else if (choice == 2) {
                    refundTicket(trains, numTrains, &users[loggedInUserIndex]);
                } else if (choice == 3) {
                    checkTrainStatus(trains, numTrains);
                } else if (choice == 4) {
                    addTrain(trains, &numTrains);
                } else if (choice == 5) {
                    printf("Logging out...\n");
                    loggedInUserIndex = -1;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            } else {
                if (choice == 1) {
                    bookTicket(trains, numTrains, &users[loggedInUserIndex]);
                } else if (choice == 2) {
                    refundTicket(trains, numTrains, &users[loggedInUserIndex]);
                } else if (choice == 3) {
                    checkTrainStatus(trains, numTrains);
                } else if (choice == 4) {
                    printf("Logging out...\n");
                    loggedInUserIndex = -1;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            }
        }
    }

    return 0;
}
