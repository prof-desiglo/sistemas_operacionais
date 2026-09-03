#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ps -o pid,ppid,stat,cmd -p 1644,1645
int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Processo filho
        printf("Filho: PID = %d\n", getpid());
        printf("Filho terminando...\n");
        exit(0);
    } else {
        // Processo pai
        printf("Pai: PID = %d\n", getpid());
        printf("Filho: PID = %d\n", pid);

        printf("Pai continua executando...\n");

        // Não chama wait()
        sleep(30);

        printf("Pai terminando...\n");
    }

    return 0;
}
