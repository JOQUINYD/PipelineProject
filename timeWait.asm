section .data

  timeval:
    tv_sec  dd 0
    tv_usec dd 0

section .text

global  _start1

_start1:

  ; Sleep for 5 seconds and 0 nanoseconds
  mov dword [tv_sec], 0
  mov dword [tv_usec], 521000000
  mov rax, 162
  mov rbx, timeval
  mov rcx, 0
  syscall


