#include <stdio.h>
#include <pthread.h>

int contador = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *incrementar(void *arg){
    for (int i = 0; i < 100000; i++){
        pthread_mutex_lock(&mutex); //comente aqui e em baixo para simular o erro

        contador++;

        pthread_mutex_unlock(&mutex); //comente aqui e em cima para simular o erro
    }

    return NULL;
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, incrementar, NULL);
    pthread_create(&t2, NULL, incrementar, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Contador = %d\n", contador);

    pthread_mutex_destroy(&mutex);

    return 0;
}
