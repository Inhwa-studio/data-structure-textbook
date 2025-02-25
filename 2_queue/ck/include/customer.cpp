#include "customer.hpp"

// Default constructor initializes values to -1 (indicating unset state)
Customer::Customer() : 
id(-1), 
arrivalTime(-1), 
totalServiceTime(-1),
serviceTime(0)
{

}

// Set customer ID
void Customer::setId(int newId) {
    id = newId;
}

// Get customer ID
int Customer::getId() const {
    return id;
}

// Set customer arrival time
void Customer::setArrivalTime(int time) {
    arrivalTime = time;
}

// Get customer arrival time
int Customer::getArrivalTime() const {
    return arrivalTime;
}

// Set customer service time
void Customer::setTotalServiceTime(int time) {
    totalServiceTime = time;
}

// Get customer service time
int Customer::getTotalServiceTime() const {
    return totalServiceTime;
}

void Customer::increaseServiceTime(){
    ++serviceTime;
    return;
}

int Customer::getServiceTime() const{
    return serviceTime;
}
