#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {

    int cliente;

    cliente = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    struct sockaddr_in servidor;

    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(5000);

    inet_pton(
        AF_INET,
        "127.0.0.1",
        &servidor.sin_addr
    );

    connect(
        cliente,
        (struct sockaddr *)&servidor,
        sizeof(servidor)
    );

    char mensagem[] = "Olá, servidor!";

    write(
        cliente,
        mensagem,
        strlen(mensagem) + 1
    );

    char resposta[100];

    read(
        cliente,
        resposta,
        sizeof(resposta)
    );

    printf("Servidor respondeu: %s\n", resposta);

    close(cliente);

    return 0;
}
