#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore; 
void *thread_function(void *arg) 
{
    sem_wait(&semaphore);  
    printf("Thread %ld is executing\n", (long)arg);
    sleep(1);  
    printf("Thread %ld is releasing the semaphore\n", (long)arg);
    sem_post(&semaphore);  
    return NULL;
}

int main() 
{
    pthread_t t1, t2;
    
    sem_init(&semaphore, 0, 1);  

    pthread_create(&t1, NULL, thread_function, (void *)1);
    pthread_create(&t2, NULL, thread_function, (void *)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore);  
    return 0;
}
