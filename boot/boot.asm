; boot.asm - setor de boot que entra em modo protegido (32 bits)
;
; Montar:   nasm -f bin boot.asm -o boot.bin
; Executar: qemu-system-i386 -drive format=raw,file=boot.bin

[bits 16]
[org 0x7C00]

start:
    cli
    jmp 0x0000:init             ; normaliza CS = 0 (algumas BIOS entregam 07C0:0000)

init:
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    ; Habilita a linha A20 (método rápido, porta 0x92)
    in  al, 0x92
    or  al, 2
    out 0x92, al

    ; Carrega a GDT
    lgdt [_gdtr]

    ; Liga o bit PE (Protection Enable) em CR0
    mov eax, cr0
    or  eax, 1
    mov cr0, eax

    ; Far jump: carrega CS com o seletor de código (índice 1 << 3 = 0x08)
    jmp dword (1 << 3):start32

align 16
_gdtr:
    dw _gdt_end - _gdt - 1      ; limite = tamanho - 1 (23)
    dd _gdt                     ; endereço base da GDT

align 16
_gdt:
    ; 0x00: descritor nulo (obrigatório)
    dd 0x00, 0x00
    ; 0x08: código 32 bits (base 0, limite 4 GB, 0x9A = presente, ring 0, executável/legível)
    db 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x9A, 0xCF, 0x00
    ; 0x10: dados 32 bits (base 0, limite 4 GB, 0x92 = presente, ring 0, gravável)
    db 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x92, 0xCF, 0x00
    ;  lim  lim  base base base acesso flags|lim base
_gdt_end:

[bits 32]
start32:
    mov ax, (2 << 3)            ; seletor de dados = 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000

    ; Escreve "OK" (branco sobre verde) no canto da tela em modo texto
    mov dword [0xB8000], 0x2F4B2F4F

.halt:
    hlt
    jmp .halt

; Preenche até 510 bytes e adiciona a assinatura de boot
times 510 - ($ - $$) db 0
dw 0xAA55
