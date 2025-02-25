#include <iostream>
#include <cstdlib> 
#include <ctime> 

#include "./include/queue.hpp"
#include "./include/customer.hpp"

int main() {

    int time = 0;
    int nCustomer = 0;
    int totalWaitTime = 0;
    int finalCustomer = 0;

    srand(static_cast<unsigned int>(std::time(0)));  // Seed random number generator
    Queue<Customer> queue(100);



    while ( true ){
        printf("Current time: %d \n", time);

        if ( time == 100 ){
            break;
        }
        
        int randomValue = rand() % 11;  // Generate a random number between 0 and 10

        if ( randomValue < 3 ){
            ++nCustomer;
            Customer customer;
            customer.setId( ++nCustomer );
            customer.setArrivalTime( time );
            customer.setTotalServiceTime( rand() % 3 + 1 );

            queue.enqueue(customer);

            printf("\tCustomer %d arrives at %d minute. Service time = %d minutes.\n", customer.getId(), customer.getArrivalTime(), customer.getTotalServiceTime());
        }

        if( !queue.is_empty() ){
            Customer& currentCustomer = queue.peek();
            // Customer currentCustomer = queue.peek();
            if( currentCustomer.getServiceTime() == 0 ){                
                printf("\tCustomer %d starts service at %d minute(s). Wating time is %d minute(s).\n", currentCustomer.getId(), time, time - currentCustomer.getArrivalTime());

                totalWaitTime += time - currentCustomer.getArrivalTime();
                finalCustomer = currentCustomer.getId() + 1 ; 
                currentCustomer.increaseServiceTime();
            }
            else if ( currentCustomer.getServiceTime() <= currentCustomer.getTotalServiceTime() ){
                printf("\tCustomner %d is being served.\n", currentCustomer.getId());
                currentCustomer.increaseServiceTime();
            }
            else {
                queue.dequeue();
            }
        }
        ++time;
    }

    printf("Average Wating time : %.2f minute(s).\n", (double) totalWaitTime / finalCustomer);
    return 0;
}
