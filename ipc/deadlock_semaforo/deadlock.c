#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *arg){
    pthread_mutex_lock(&mutexA);

    printf("Thread 1: adquiriu mutex A\n");

    sleep(1);

    printf("Thread 1: tentando adquirir mutex B\n");
    pthread_mutex_lock(&mutexB);

    printf("Thread 1: adquiriu mutex B\n");

    pthread_mutex_unlock(&mutexB);
    pthread_mutex_unlock(&mutexA);

    return NULL;
}

void *thread2(void *arg){
    pthread_mutex_lock(&mutexB);

    printf("Thread 2: adquiriu mutex B\n");

    sleep(1);

    printf("Thread 2: tentando adquirir mutex A\n");
    pthread_mutex_lock(&mutexA);

    printf("Thread 2: adquiriu mutex A\n");

    pthread_mutex_unlock(&mutexA);
    pthread_mutex_unlock(&mutexB);

    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
