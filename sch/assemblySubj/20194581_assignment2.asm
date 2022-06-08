%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ;input a, b
    GET_DEC 2,[a]
    GET_DEC 2,[b]
    
    ;MyAdd(a, b)
    PUSH word [a]
    PUSH word [b]
    CALL MyAdd
    mov [c],ax
    PRINT_DEC 2,c
    NEWLINE

    ;MySub(a, b)
    PUSH word [a]
    PUSH word [b]
    CALL MySub    
    mov [d],ax  
    PRINT_DEC 2,d
    NEWLINE
    
    ;MyMul(a, b)
    PUSH word [a]
    PUSH word [b]
    CALL MyMul
    mov [f],ax
    PRINT_DEC 2,f
    NEWLINE
    
    ;MyDiv(a, b)
    PUSH word [a]
    PUSH word [b]
    CALL MyDiv    
    mov [e],al
    PRINT_DEC 2,e
    NEWLINE
    
    xor rax, rax
    ret
    
MyAdd:
    push rbp
    mov rbp, rsp
    mov ax, [rbp+8+8]
    mov bx, [rbp+8+8+2]
    add ax, bx
    leave
    ret
     
MySub:
    push rbp
    mov rbp, rsp
    mov ax, [rbp+8+8+2]
    mov bx, [rbp+8+8]
    sub ax, bx
    leave
    ret
    
MyDiv:
    push rbp
    mov rbp, rsp
    mov dx, 0
    mov ax, [rbp+8+8+2]
    mov bl, [rbp+8+8]
    div bl
    leave
    ret
    
MyMul:
    push rbp
    mov rbp, rsp
    mov ax, [rbp+8+8]
    mov bx, [rbp+8+8+2]
    mul bx
    leave
    ret
         
section .bss
    a resw 1
    b resw 1 
    c resw 1
    d resw 1
    e resw 1
    f resw 1