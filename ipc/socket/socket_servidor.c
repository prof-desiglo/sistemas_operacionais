#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {

    int servidor;
    int cliente;

    char buffer[100];

    servidor = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    struct sockaddr_in endereco;

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(5000);

    bind(
        servidor,
        (struct sockaddr *)&endereco,
        sizeof(endereco)
    );

    listen(servidor, 5);

    printf("Servidor esperando conexão...\n");

    cliente = accept(
        servidor,
        NULL,
        NULL
    );

    printf("Cliente conectado!\n");

    read(
        cliente,
        buffer,
        sizeof(buffer)
    );

    printf("Recebi: %s\n", buffer);

    char resposta[] = "Mensagem recebida pelo servidor!";

    write(
        cliente,
        resposta,
        strlen(resposta) + 1
    );

    close(cliente);
    close(servidor);

    return 0;
}
