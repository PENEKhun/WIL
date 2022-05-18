%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp
    PRINT_STRING msg_input
    GET_DEC 2, data_max
    NEWLINE
    
    mov [data_size], word 0
    mov edx, 1; index: edx~100
L1:
    mov bl,3
    mov ax,dx
    div bl
    cmp ah,0
    jnz L_next
    mov eax,0
    mov ax,[data_size]
    mov [data + eax*2], dx
    inc eax
    mov [data_size], ax
L_next:
    inc edx
    cmp dx, [data_max]
    jle L1
    PRINT_STRING msg_count
    PRINT_DEC 2, [data_size]
    NEWLINE
    mov eax,0
L_print:
    PRINT_DEC 2, [data+eax*2]
    NEWLINE
    inc eax
    cmp ax,word [data_size]
    jl L_print ;
   ;additonal code Start
    mov [total], word 0
    jmp cal_init
cal_init: 
    mov eax, 0
    mov ebx, 0
    mov cx, word [data_size]
    cmp cx, 0
    jz cal_next
cal_next:
    add ebx, [data+eax*2]
    inc eax
    dec cx
    cmp cx, 0
    jnbe cal_next
    mov [total], ebx
   ;additional code end
    PRINT_STRING msg_total
    PRINT_DEC 2, total
        
    xor rax, rax
    ret
    
section .data
    msg_input db '# input max number:', 0x00
    msg_count db '# number count ', 0x00
    msg_total db '# total: ', 0x00
    
section .bss
    data_max resw 1
    data_size resw 1
    data resw 100
    total resw 1
            