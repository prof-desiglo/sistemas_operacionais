#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>

int main() {

    mqd_t fila;

    fila = mq_open(
        "/minha_fila",
        O_RDONLY
    );

    if (fila == -1) {
        perror("mq_open");
        return 1;
    }

    char mensagem[100];
    unsigned int prioridade;

    mq_receive(
        fila,
        mensagem,
        sizeof(mensagem),
        &prioridade
    );

    printf("Mensagem recebida: %s\n", mensagem);

    mq_close(fila);

    mq_unlink("/minha_fila");

    return 0;
}
