#include "queue.h"
#define MAX_CUSTOMER 100

int main(){
    int time = 0;
    int nCustomer = 0;
    int totalTime = 0;
    int finalCustomer = 0;

    queue* customerQue = create(MAX_CUSTOMER);

    while (1) {
        printf("Current time = %d\n", time);

        if (time == 100) break;

        int check = rand() % 10;
        if (check < 3) {
            int currCustomer = nCustomer++;
            int serviceTime = rand() % 3 + 1;
            int arriveTime = time;

            elem tmp;
            tmp.nCustomer = currCustomer;
            tmp.arriveTime = arriveTime;
            tmp.serviceTime = serviceTime;
            tmp.playTime = 0;
            
            enqueue(customerQue, tmp);
            
            printf("Customer %d arrives at %d minute. Service time = %d minutes.\n", currCustomer, arriveTime, serviceTime);
        }

        if (!is_empty(customerQue)){
            elem* now = &customerQue->list[(customerQue->front + 1) % customerQue->size];
            if (now->playTime == 0) {
                printf("Customer %d starts service at %d minute(s). Wating time is %d minute(s).\n", now->nCustomer, time, time - now->arriveTime);
                totalTime += time - now->arriveTime;
                finalCustomer = now->nCustomer + 1;
                now->playTime += 1;
            }
            else if (now->playTime <= now->serviceTime){
                printf("Customner %d is being served.\n", now->nCustomer);
                now->playTime += 1;
            }

            if (now->playTime > now->serviceTime){
                dequeue(customerQue);
            }
        }
        time++;

    }
    printf("Average Wating time : %.2f minute(s).\n", (double) totalTime / finalCustomer);
    return 0;
}
