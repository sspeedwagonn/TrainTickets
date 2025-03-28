#include "library.h"
#include <stdio.h>

struct Train {
    int trainId;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float ticketPrice;
};

struct User {
    char username[50];
    char password[50];
    int tripsTaken;
};

void loginMenu() {
    printf("----------\n");
    printf("Login Menu\n");
    printf("1. Login\n");
    printf("2. Quit\n");
    printf("----------");
}

int main() {
    loginMenu();
}