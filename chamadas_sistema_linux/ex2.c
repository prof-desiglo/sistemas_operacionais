#include <unistd.h>

int main(void){
    const char msg[] = "Olá, mundo!\n";

    write(1, msg, sizeof(msg) - 1);

    return 0;
}
