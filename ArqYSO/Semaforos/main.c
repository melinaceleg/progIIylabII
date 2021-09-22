#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SLOTS 2
#define buffer 100

///slots garantiza la cantidad maxima de items qie va a producir antes de que el otro consuma
sem_t mutex,slots,items;

void* producir()
{
 for (int i = 0; i < buffer; i++)
 {
     sem_wait(&slots);
     sem_wait(&mutex);
     printf("Produce item %i\n", i+1);
     sem_post(&mutex);
     sem_post(&items);
 }

}

void* consumir()
{
    for (int i = 0 ; i < buffer; i++)
    {
        sem_wait(&items);
        sem_wait(&mutex);
        printf("consume item %i\n", i+1);
        sem_post(&mutex);
        sem_post(&slots);
    }
}


int main()
{
    pthread_t consumidor, productor;
    sem_init(&mutex,0,1);
    sem_init(&slots,0,SLOTS);
    sem_init(&items,0,0);

    pthread_create(&consumidor,NULL,consumir,NULL);
    pthread_create(&productor,NULL,producir,NULL);
    pthread_join(consumidor,NULL);
    pthread_join(productor,NULL);

    sem_destroy(&mutex);
    sem_destroy(&slots);
    sem_destroy(&items);
    return 0;
}
