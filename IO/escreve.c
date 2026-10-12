#include <fcntl.h>
#include <unistd.h>

int main() {
    char buf[100];
    int fd = open("/dev/urandom", O_RDONLY);   // devolve um descritor
    ssize_t n = read(fd, buf, sizeof(buf));    // lê até 100 bytes
    write(1, buf, n);                          // fd 1 = saída padrão
    close(fd);
    return 0;
}
