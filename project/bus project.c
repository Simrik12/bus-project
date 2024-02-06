#include <stdio.h>

#define MAX_SEATS 20

int seats[MAX_SEATS] = {0};

void reserveSeat(int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        if (seats[seatNumber - 1] == 0) {
            seats[seatNumber - 1] = 1;
            printf("Seat %d is reserverd.\n", seatNumber);
        } else {
            printf("Seat %d is already reserved.\n", seatNumber);
        }
    } else {
        printf("Invalid seat number.\n");
    }
}

void cancelReservation(int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        if (seats[seatNumber - 1] == 1) {
            seats[seatNumber - 1] = 0;
            printf("Reservation for seat %d is canceled.\n", seatNumber);
        } else {
            printf("Seat %d is not reserved.\n", seatNumber);
        }
    } else {
        printf("The seat number is invalid.\n");
    }
}

void checkAvailability() {
    int availableSeats = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == 0) {
            availableSeats++;
        }
    }
    printf("Number of available seats: %d\n", availableSeats);
}

int main() {
    int choice, seatNumber;

    do {
        printf("\nBus Seat Reservation System\n");
        printf("1. Reserve a seat\n");
        printf("2. Cancel the reservation\n");
        printf("3. Check seat availability\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter seat number: ");
                scanf("%d", &seatNumber);
                reserveSeat(seatNumber);
                break;
            case 2:
                printf("Enter seat number: ");
                scanf("%d", &seatNumber);
                cancelReservation(seatNumber);
                break;
            case 3:
                checkAvailability();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("The choice is invalid. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
