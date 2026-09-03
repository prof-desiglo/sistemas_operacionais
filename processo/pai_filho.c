#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t pid = fork();

    if (pid == 0) {
        printf("Sou o processo filho! PID = %d\n", getpid());
    }
    else if (pid > 0) {
        printf("Sou o processo pai! PID = %d\n", getpid());
    }
    else {
        printf("Erro ao criar processo!\n");
    }

    return 0;
}