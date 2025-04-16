#pragma once
#include <iostream>
#include <string>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string email;

public:
    // Constructor
    Contact(std::string name_, std::string phoneNumber_, std::string email_);
    Contact(std::string name_);
    Contact();

    // Getter functions
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    // Overloading comparison operator (used for sorting by name)
    bool operator<(const Contact& other) const;
    bool operator>(const Contact& other) const;
    bool operator==(const Contact& other) const;
    bool operator!=(const Contact& other) const;

    // Overloading stream output operator (for std::cout)
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
};
