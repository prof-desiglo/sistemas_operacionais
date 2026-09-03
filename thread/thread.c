#include <stdio.h>
#include <pthread.h>

// pthread - IEEE 1003.1c

void *funcao(void *arg) {
    printf("Thread executando!\n");
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, funcao, NULL);

    pthread_join(thread, NULL);

    printf("Programa terminou.\n");

    return 0;
}