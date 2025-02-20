
#pragma once

class Customer {
  private: 
    int id;
    int arrivalTime;
    int totalServiceTime;
    int serviceTime;

  public: 
    Customer();
    void setId(int newId);
    int getId() const;
    void setArrivalTime(int time);
    int getArrivalTime() const;
    void setTotalServiceTime(int time);
    int getTotalServiceTime() const;
    void increaseServiceTime();
    int getServiceTime() const;
};
