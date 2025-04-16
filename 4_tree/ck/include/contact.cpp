#include "contact.hpp"

// Constructor
Contact::Contact(std::string name_, std::string phoneNumber_, std::string email_)
: name(name_)
, phoneNumber(phoneNumber_)
, email(email_)
{

}

Contact::Contact(std::string name_)
: name(name_)
, phoneNumber("000-0000-0000")
, email("JohnDoe0101@gmail.com") 
{

}


Contact::Contact()
: name("John doe")
, phoneNumber("000-0000-0000")
, email("JohnDoe0101@gmail.com") 
{

}

// Getter functions
std::string Contact::getName() const { 
  return name; 
}

std::string Contact::getPhoneNumber() const { 
  return phoneNumber; 
}

std::string Contact::getEmail() const { 
  return email; 
}

// Overloading comparison operator (used for sorting by name)
bool Contact::operator<(const Contact& other) const {
  return name < other.name; // Name 기준으로 크기 비교
}

// Overloading comparison operator (used for sorting by name)
bool Contact::operator>(const Contact& other) const {
  return name > other.name; // Name 기준으로 크기 비교
}

// Overloading comparison operator (used for sorting by name)
bool Contact::operator==(const Contact& other) const {
  return this->name == other.name;
}

// Overloading comparison operator (used for sorting by name)
bool Contact::operator!=(const Contact& other) const {
  return !(*this == other);
}

// Overloading stream output operator (for std::cout)
std::ostream& operator<<(std::ostream& os, const Contact& Contact) {
    os << "Name: " << Contact.name 
       << ",\tPhone Number: " << Contact.phoneNumber
       << ",\tEmail: " << Contact.email;
    return os;
}
