#include <stdio.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {

    mqd_t fila;

    struct mq_attr atributos;

    atributos.mq_flags = 0;
    atributos.mq_maxmsg = 10;
    atributos.mq_msgsize = 100;
    atributos.mq_curmsgs = 0;

    fila = mq_open(
        "/minha_fila",
        O_CREAT | O_WRONLY,
        0644,
        &atributos
    );

    if (fila == -1) {
        perror("mq_open");
        return 1;
    }

    char mensagem[] = "Olá do produtor!";

    mq_send(
        fila,
        mensagem,
        strlen(mensagem) + 1,
        1
    );

    printf("Mensagem enviada!\n");

    mq_close(fila);

    return 0;
}
