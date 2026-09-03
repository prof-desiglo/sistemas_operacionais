#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void tratar_interrupcao(int sinal) {
    printf("\nInterrupcao recebida! Sinal: %d\n", sinal);
}

void tratar_sigterm(int sinal) {
    printf("\nSIGTERM (15) recebido. Encerrando o programa...\n");
    exit(0);
}

int main() {
    signal(SIGINT, tratar_interrupcao); // Cnt+C
	signal(SIGTERM, tratar_sigterm); // Kill

    while (1) {
        printf("Programa executando...\n");
        sleep(1);
    }

    return 0;
}