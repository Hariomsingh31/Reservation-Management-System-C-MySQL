#ifndef RESERVATION_H
#define RESERVATION_H

#include "Database.h"
#include <string>

class Reservation {
private:
    std::string name, date, time;
    int seats;
    Database db;

public:
    Reservation();
    void addReservation();
    void viewReservations();
    void cancelReservation();
};

#endif
