#ifndef TRAINTICKETS_LIBRARY_H
#define TRAINTICKETS_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
_____                 . . . . . o o o o o
  __|[_]|__ ___________ _______    ____      o
 |[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][.
_|________|_[_________]_[________]_|__|________)<
  oo    oo 'oo      oo ' oo    oo 'oo 0000---oo\_
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#define ALL_TRAINS 50

typedef struct {
    int trainId;
    char trainName[50];
    char source[50];
    char destination[50];
    int trainCars;
    int totalSeats;
    int availableSeats;
    float ticketPrice;
} Train;

typedef struct {
    char username[50];
    char password[50];
    int tripsTaken;
} User;


void loginMenu();
void dashboard(const char *username);

int login(const User *users, int numUsers, const char *username, const char *password);
int signUp(User **users, int *numUsers);

void bookTicket(Train trains[], int numTrains, User *currentUser);
void refundTicket(Train trains[], int numTrains, User *currentUser);
void checkTrainStatus(Train trains[], int numTrains);
void addTrain(Train trains[], int *numTrains);

#endif //TRAINTICKETS_LIBRARY_H