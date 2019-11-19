global _start

section .data

    timespec:
        tv_sec  dq 1
        tv_nsec dq 200000000

section .text

    _start:
        mov     rax, 35
        mov     rdi, timespec
        xor     rsi, rsi
        syscall
        ...
