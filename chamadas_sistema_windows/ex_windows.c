#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char mensagem[] = "Ola Windows!\n";
    DWORD bytesEscritos;

    WriteFile(
        hConsole,             // Handle
        mensagem,             // Dados
        sizeof(mensagem) - 1,  // Quantidade de bytes
        &bytesEscritos,       // Bytes realmente escritos
        NULL                  // Operacao sincronica
    );

    return 0;
}