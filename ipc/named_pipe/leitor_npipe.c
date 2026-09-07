#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("canal", O_RDONLY);

    char buffer[100];

    int n = read(fd, buffer, sizeof(buffer));

    write(STDOUT_FILENO, buffer, n);

    close(fd);

    return 0;
}
