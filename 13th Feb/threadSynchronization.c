#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cond;
int ready = 0;

void *worker_thread(void *arg) 
{
    pthread_mutex_lock(&lock);
    while (!ready) 
    {
        pthread_cond_wait(&cond, &lock);  
    }
    printf("Thread received signal!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() 
{
    pthread_t thread;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread, NULL, worker_thread, NULL);
    
    sleep(1);  
    pthread_mutex_lock(&lock);
    ready = 1;
    pthread_cond_signal(&cond);  
    pthread_mutex_unlock(&lock);

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}
