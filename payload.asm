BITS    16
ORG     0x7c00
jmp start

start:
    call clr_scr
    mov ax,cs
    mov ds,ax
    mov si,msg
    call print

print:
    push ax
    cld

next:
    mov al,[si]
    cmp al,0
    je done
    call print_char
    inc si
    jmp next

done:
    jmp $

print_char:
    mov ah,0x0e
    int 0x10
    ret

clr_scr:
    mov ah, 0x07
    mov al, 0x00
    mov bh, 0x09 
    mov cx, 0x0000 
    mov dx, 0x184f
    int 0x10
    ret

msg:    db  "Your computer has died horribly.",13,10,"Temptation leads to evil.",0
times 510 - ($-$$) db 0
dw        0xaa55