#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#define NUM_TICKETS 100

int tickets_available1 = NUM_TICKETS;
int tickets_available2 = NUM_TICKETS;
int tickets_available3 = NUM_TICKETS;
pthread_mutex_t ticket_mutex;

void* customer_thread1(void* arg) {
    int customer_id = *(int*)arg;
    int tickets_to_purchase1;
    printf("Customer is buying how many tickets \n");
    scanf("%d",&tickets_to_purchase1);
    pthread_mutex_lock(&ticket_mutex);

    if (tickets_available1 >= tickets_to_purchase1) {
        tickets_available1 -= tickets_to_purchase1;
        printf("Customer successfully purchased %d tickets. %d tickets remaining for movie 1\n", tickets_to_purchase1, tickets_available1);
    } else {
        printf("Customer couldn't purchase %d tickets. Only %d tickets remaining movie 1\n", tickets_to_purchase1, tickets_available1);
    }

    pthread_mutex_unlock(&ticket_mutex);

    return NULL;
}

void* customer_thread2(void* arg) {
    int customer_id = *(int*)arg;
    int tickets_to_purchase2;
    printf("Customer is buying how many tickets \n");
    scanf("%d",&tickets_to_purchase2);
    pthread_mutex_lock(&ticket_mutex);

    if (tickets_available2 >= tickets_to_purchase2) {
        tickets_available2 -= tickets_to_purchase2;
        printf("Customer successfully purchased %d tickets. %d tickets remaining for movie 2\n", tickets_to_purchase2, tickets_available2);
    } else {
        printf("Customer couldn't purchase %d tickets. Only %d tickets remaining for movie 2\n", tickets_to_purchase2, tickets_available2);
    }

    pthread_mutex_unlock(&ticket_mutex);

    return NULL;
}

void* customer_thread3(void* arg) {
    int customer_id = *(int*)arg;
    int tickets_to_purchase3;
    printf("Customer is buying how many tickets \n");
    scanf("%d",&tickets_to_purchase3);
    pthread_mutex_lock(&ticket_mutex);

    if (tickets_available3 >= tickets_to_purchase3) {
        tickets_available3 -= tickets_to_purchase3;
        printf("Customer successfully purchased %d tickets. %d tickets remaining for movie 3\n", tickets_to_purchase3, tickets_available3);
    } else {
        printf("Customer couldn't purchase %d tickets. Only %d tickets remaining for movie 3\n", tickets_to_purchase3, tickets_available3);
    }

    pthread_mutex_unlock(&ticket_mutex);

    return NULL;
}
int main() {
    pthread_t customers[100];
    int customer_ids[100];
    pthread_mutex_init(&ticket_mutex, NULL);
    int i,a;
    printf("enter the customer in line");
    scanf("%d",&a);
    for (i=0;i<a;i++){
        int j,id=0;
        printf("Enter \n 1 for m1 \n 2 for m2 \n 3 for m3");
        scanf("%d",&j);
        if (j==1){
            pthread_create(&customers[id], NULL, customer_thread1, &customer_ids[id]);
            sleep(5);
        }  
        if (j==2){
            pthread_create(&customers[id], NULL, customer_thread2, &customer_ids[id]);
            sleep(5);
        }  
        if (j==3){
            pthread_create(&customers[id], NULL, customer_thread3, &customer_ids[id]);
            sleep(5);
        }
        id++;
    }    
    for (int k = 0; k < i; k++) {
        pthread_join(customers[k], NULL);
    }

    pthread_mutex_destroy(&ticket_mutex);
    return 0;
}
