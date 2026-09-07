#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("canal", O_WRONLY);

    char mensagem[] = "Mensagem através do Named Pipe\n";

    write(fd, mensagem, sizeof(mensagem));

    close(fd);

    return 0;
}
