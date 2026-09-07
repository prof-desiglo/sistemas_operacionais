#include <stdio.h>
#include <unistd.h>

int main() {
    int numero = 123456;

    printf("PID: %d\n", getpid());
    printf("Endereco de numero: %p\n", (void *)&numero);

    while (1) {
        sleep(1);
    }

    return 0;
}
