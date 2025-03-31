#include "library.h"

void loginMenu() {
    printf("\n----------\n");
    printf("Login Menu:\n");
    printf("1. Sign Up\n");
    printf("2. Login\n");
    printf("3. Quit\n");
    printf("----------\n");
}

void dashboard(const char *username) {
    printf("\n----------\n");
    printf("Dashboard for %s:\n", username);
    printf("1. Book Ticket\n");
    printf("2. Refund Ticket\n");
    printf("3. Check Train Status\n");
    if (strcmp(username, "admin") == 0) {
        printf("4. Add Train\n");
        printf("5. Logout\n");
    } else {
        printf("4. Logout\n");
    }
    printf("----------\n");
}