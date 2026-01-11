#include "Database.h"
#include <iostream>

Database::Database() {
    conn = mysql_init(NULL);
}

void Database::connect() {
    if (!mysql_real_connect(conn, "localhost", "root", "", 
        "reservation_db", 0, NULL, 0)) {
        std::cout << "Database Connection Failed\n";
    } else {
        std::cout << "Database Connected Successfully\n";
    }
}

MYSQL* Database::getConnection() {
    return conn;
}
