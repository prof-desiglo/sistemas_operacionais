#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[100];

    pipe(fd);

    if (fork() == 0) {
        // FILHO
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));

        printf("Filho recebeu: %s\n", buffer);
        close(fd[0]);
    }
    else {
        // PAI
        close(fd[0]);
        char mensagem[] = "Olá, filho!";

        write(fd[1], mensagem, strlen(mensagem) + 1);
        close(fd[1]);
    }

    return 0;
}
