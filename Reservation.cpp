#include "Reservation.h"
#include <iostream>

Reservation::Reservation() {
    db.connect();
}

void Reservation::addReservation() {
    std::cout << "Enter Name: ";
    std::cin >> name;
    std::cout << "Enter Date: ";
    std::cin >> date;
    std::cout << "Enter Time: ";
    std::cin >> time;
    std::cout << "Enter Seats: ";
    std::cin >> seats;

    std::string query =
        "INSERT INTO reservations (name, date, time, seats) VALUES ('" +
        name + "','" + date + "','" + time + "'," + std::to_string(seats) + ")";

    mysql_query(db.getConnection(), query.c_str());
    std::cout << "Reservation Added Successfully\n";
}

void Reservation::viewReservations() {
    mysql_query(db.getConnection(), "SELECT * FROM reservations");
    MYSQL_RES* res = mysql_store_result(db.getConnection());
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res))) {
        std::cout << "ID: " << row[0]
                  << " Name: " << row[1]
                  << " Date: " << row[2]
                  << " Time: " << row[3]
                  << " Seats: " << row[4] << "\n";
    }
}

void Reservation::cancelReservation() {
    int id;
    std::cout << "Enter Reservation ID to Cancel: ";
    std::cin >> id;

    std::string query =
        "DELETE FROM reservations WHERE id=" + std::to_string(id);

    mysql_query(db.getConnection(), query.c_str());
    std::cout << "Reservation Cancelled\n";
}
