.section .data
msg:
    .ascii "Ola, mundo!\n"
len = . - msg

.section .text
.globl _start

_start:
    mov $1, %rax          # syscall write
    mov $1, %rdi          # fd = stdout
    lea msg(%rip), %rsi        # endereço da mensagem
    mov $len, %rdx        # tamanho da mensagem
    syscall

    mov $60, %rax         # syscall exit
    xor %rdi, %rdi          # código de saída
    syscall
	
	
	#gcc -nostdlib -no-pie write.s -o write
