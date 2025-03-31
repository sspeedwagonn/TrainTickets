#include "library.h"

int login(const User *users, const int numUsers, const char *username, const char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int signUp(User **users, int *numUsers) {
    User newUser;
    int duplicate;

    do {
        duplicate = 0;
        printf("Enter new username: ");
        scanf("%s", newUser.username);
        for (int i = 0; i < *numUsers; i++) {
            if (strcmp((*users)[i].username, newUser.username) == 0) {
                printf("Username already exists. Please choose another username.\n");
                duplicate = 1;
                break;
            }
        }
    } while (duplicate);

    printf("Enter new password: ");
    scanf("%s", newUser.password);
    newUser.tripsTaken = 0;

    *users = realloc(*users, (*numUsers + 1) * sizeof(User));
    if (*users == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    (*users)[*numUsers] = newUser;
    (*numUsers)++;

    printf("Sign-up successful! You can now log in.\n");
    return 0;
}