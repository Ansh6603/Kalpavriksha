#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
int counter=0;
void* increment_counter(void* arg)
{
    pthread_mutex_lock(&lock);
    counter++;
    printf("Counter : %d \n",counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main()
{
    pthread_t thread1,thread2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&thread1,NULL,increment_counter,NULL);
    pthread_create(&thread2,NULL,increment_counter,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}