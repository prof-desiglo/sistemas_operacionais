#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t vagas;

void *carro(void *arg){
    int id = *(int *)arg;

    printf("Carro %d esperando por uma vaga...\n", id);

    // Tenta ocupar uma vaga
    sem_wait(&vagas);

    printf("Carro %d entrou no estacionamento.\n", id);

    // Simula o tempo estacionado
    sleep(2);

    printf("Carro %d saiu do estacionamento.\n", id);

    // Libera a vaga
    sem_post(&vagas);

    return NULL;
}

int main(){
    pthread_t threads[5];
    int ids[5];

    // Cria semáforo com 3 vagas disponíveis
    sem_init(&vagas, 0, 3);

    // Cria 5 threads
    for (int i = 0; i < 5; i++)
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, carro, &ids[i]);
    }

    // Espera todas as threads terminarem
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&vagas);

    return 0;
}
