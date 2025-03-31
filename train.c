#include "library.h"

void bookTicket(Train trains[], int numTrains, User *currentUser) {
    int trainId;
    printf("Enter Train ID: ");
    scanf("%d", &trainId);
    
    int trainIndex = -1;
    for (int i = 0; i < numTrains; i++) {
        if (trains[i].trainId == trainId) {
            trainIndex = i;
            break;
        }
    }
    
    if (trainIndex == -1) {
        printf("Train with ID %d not found.\n", trainId);
        return;
    }
    
    int seatsToBook;
    printf("Enter number of seats to book: ");
    scanf("%d", &seatsToBook);
    
    if (trains[trainIndex].availableSeats < seatsToBook) {
        printf("Not enough seats available. Available seats: %d\n", trains[trainIndex].availableSeats);
        return;
    }
    
    trains[trainIndex].availableSeats -= seatsToBook;
    currentUser->tripsTaken += seatsToBook;
    
    float discount = 0.0;
    if (currentUser->tripsTaken >= 20)
        discount = 0.20;
    else if (currentUser->tripsTaken >= 10)
        discount = 0.10;
    
    float totalCost = seatsToBook * trains[trainIndex].ticketPrice * (1 - discount);
    printf("Ticket booked successfully! Total cost: %.2f (Discount applied: %.0f%%).\n", totalCost, discount * 100);
}

void refundTicket(Train trains[], int numTrains, User *currentUser) {
    int trainId;
    printf("Enter Train ID for refund: ");
    scanf("%d", &trainId);
    
    int trainIndex = -1;
    for (int i = 0; i < numTrains; i++) {
        if (trains[i].trainId == trainId) {
            trainIndex = i;
            break;
        }
    }
    
    if (trainIndex == -1) {
        printf("Train with ID %d not found.\n", trainId);
        return;
    }
    
    int seatsToRefund;
    printf("Enter number of seats to refund: ");
    scanf("%d", &seatsToRefund);
    
    int bookedSeats = trains[trainIndex].totalSeats - trains[trainIndex].availableSeats;
    if (seatsToRefund > bookedSeats) {
        printf("Error: Cannot refund more seats than booked (%d booked).\n", bookedSeats);
        return;
    }
    
    trains[trainIndex].availableSeats += seatsToRefund;
    if (currentUser->tripsTaken >= seatsToRefund)
        currentUser->tripsTaken -= seatsToRefund;
    else
        currentUser->tripsTaken = 0;

    const float refundAmount = seatsToRefund * trains[trainIndex].ticketPrice;
    printf("Refund successful! Refund amount: %.2f\n", refundAmount);
}

void checkTrainStatus(Train trains[], const int numTrains) {
    int trainId;
    printf("Enter Train ID: ");
    scanf("%d", &trainId);
    
    int trainIndex = -1;
    for (int i = 0; i < numTrains; i++) {
        if (trains[i].trainId == trainId) {
            trainIndex = i;
            break;
        }
    }
    
    if (trainIndex == -1) {
        printf("Train with ID %d not found.\n", trainId);
        return;
    }
    
    printf("\n--- Train Status ---\n");
    printf("Train ID: %d\n", trains[trainIndex].trainId);
    printf("Train Name: %s\n", trains[trainIndex].trainName);
    printf("Route: %s to %s\n", trains[trainIndex].source, trains[trainIndex].destination);
    printf("Total Seats: %d\n", trains[trainIndex].totalSeats);
    printf("Available Seats: %d\n", trains[trainIndex].availableSeats);
    printf("Ticket Price: %.2f\n", trains[trainIndex].ticketPrice);
    printf("--------------------\n");
}

void addTrain(Train trains[], int *numTrains) {
    Train newTrain;
    printf("Enter Train ID: ");
    scanf("%d", &newTrain.trainId);
    printf("Enter Train Name: ");
    scanf("%s", newTrain.trainName);
    printf("Enter Source: ");
    scanf("%s", newTrain.source);
    printf("Enter Destination: ");
    scanf("%s", newTrain.destination);
    printf("Enter Number of Train Cars: ");
    scanf("%d", &newTrain.trainCars);
    printf("Enter Total Seats: ");
    scanf("%d", &newTrain.totalSeats);
    newTrain.availableSeats = newTrain.totalSeats;
    printf("Enter Ticket Price: ");
    scanf("%f", &newTrain.ticketPrice);
    
    trains[*numTrains] = newTrain;
    (*numTrains)++;
    
    printf("Train added successfully!\n");
}