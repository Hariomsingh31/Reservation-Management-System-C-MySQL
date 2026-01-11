#include "Reservation.h"
#include <iostream>

int main() {
    Reservation r;
    int choice;

    do {
        std::cout << "\n1. Add Reservation";
        std::cout << "\n2. View Reservations";
        std::cout << "\n3. Cancel Reservation";
        std::cout << "\n4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            r.addReservation();
            break;
        case 2:
            r.viewReservations();
            break;
        case 3:
            r.cancelReservation();
            break;
        }
    } while (choice != 4);

    return 0;
}
