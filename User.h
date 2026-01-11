#ifndef USER_H
#define USER_H

#include <string>
#include "Database.h"

class User {
protected:
    std::string username;
    std::string password;
    std::string role;   // admin or user
    Database db;

public:
    User();                 // Constructor
    bool login();            // Authenticate user
    std::string getRole();   // Return user role
};

#endif
