segment .text

global _determProb

_determProb:
    mov eax,edi
    cmp eax,esi
    jge  noOcurre
    mov eax,1   ; si eax = 1 entonces ocurre la probabilidad
    ret

noOcurre:
    mov eax,0   ; si eax = 0 entonces no ocurre la probabilidad
    ret
