#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {

    int *memoria = mmap(
        NULL,
        sizeof(int),
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS,
        -1,
        0
    );

    *memoria = 10;

    if (fork() == 0) {
        printf("Filho: %d\n", *memoria);

        *memoria = 50;
    } else {
        sleep(1);
        printf("Pai: %d\n", *memoria);
    }

    munmap(memoria, sizeof(int));

    return 0;
}
