#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t semaphore;
void* count(void* arg)
{
    sem_wait(&semaphore);
    printf("Thread %ld is working...\n", (long)arg);
    sleep(2); 
    printf("Thread %ld finished work.\n", (long)arg);
    sem_post(&semaphore);
    return NULL;
}
int main()
{
    pthread_t thread[5];
    sem_init(&semaphore,0,3);
    for(int iteratorI=0;iteratorI<5;iteratorI++)
    {
        pthread_create(&thread[iteratorI],NULL,count,iteratorI);
    }
    for(int iteratorI=0;iteratorI<5;iteratorI++)
    {
        pthread_join(thread[iteratorI],NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}