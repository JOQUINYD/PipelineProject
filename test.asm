segment .text

global _test1

_test1:
    enter   0,0
    mov     EAX,50
    mov     EBX,1000
    sub     EAX,20
    leave
    ret 

global _test2

_test2:
    enter   0,0
    mov     RAX,[RBP+8]
    add     RAX,[RBP+16]
    sub     RAX,[RBP+24]
    leave
    ret
