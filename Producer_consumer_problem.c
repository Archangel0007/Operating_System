#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define buffSize 1000
#include <semaphore.h>
struct{
    sem_t mutex;
    int buff[buffSize];
    int producedCount;
    int consumedCount;
}shared;
void * produce(void * arg);
void * consume(void * arg);
int main(){
    int prodThreads, consThreads, i;
    int rc=sem_init(&shared.mutex,0,1);
    printf("\nEnter the no of Producers: ");
    scanf("%d", & prodThreads);
    printf("\nEnter the no of Consumers: ");
    scanf("%d", & consThreads);

    int producerArr[prodThreads], consumerArr[consThreads];
    pthread_t producer[prodThreads], consumer[consThreads];
    pthread_setconcurrency(prodThreads + consThreads);

    for (i = 0; i < prodThreads; i++){
        producerArr[i] = 0;
        pthread_create(&producer[i],NULL,produce,(void*)&producerArr[i]);
    }
    for (i = 0; i < consThreads; i++){
        consumerArr[i] = 0;
        pthread_create(&consumer[i],NULL,consume,(void*)&consumerArr[i]);
        ;
    }
    for (i = 0; i < prodThreads; i++){
        pthread_join(producer[i],NULL);
        printf("\nThe Producer (%d) produced: [%d] Items", i, producerArr[i]);
        sleep(1);
    }
    printf("\n");
    for (i = 0; i < consThreads; i++){
        pthread_join(consumer[i],NULL);
        printf("\nThe Consumer (%d) Consumed: [%d] Items", i, consumerArr[i]);
        sleep(1);
    }
    printf("\n");
}

 

void * produce(void * arg){
    while (1){
        int x=sem_wait(&shared.mutex);
        if (shared.producedCount < buffSize){
            shared.producedCount++;
            *((int * ) arg) += 1;
            x=sem_post(&shared.mutex);
        } 
        else{
            x=sem_post(&shared.mutex);
            return NULL;
        }
    }
}

 

void * consume(void * arg){
    while (1){
        int x=sem_wait(&shared.mutex);
        if (shared.consumedCount < shared.producedCount) {
            shared.consumedCount++;
            *((int * ) arg) += 1;
            x=sem_post(&shared.mutex);
        } 
        else{
            x=sem_post(&shared.mutex);
            if (shared.consumedCount >= buffSize)
                return NULL;
        }
    }
}