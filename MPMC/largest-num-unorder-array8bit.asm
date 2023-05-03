ORG 100H
MOV AX, 6000H;
MOV DS, AX;
MOV BX, 5000H;
MOV DL, 15D;
MOV CX, 15D;

L1: MOV [BX], DL;
INC BX;
ADD DL, 10D;

LOOP L1;
MOV AX, 0000H;
MOV DX, 0000H;
MOV BX, 5000H;
MOV CX, 15D;

L2: MOV AL, [BX];
ADD DX, AX;
INC BX;
LOOP L2;
HLT;



; another solution

org 100h
mov ax, 6000h
mov ds, ax 
mov al, 30h 
mov bx, 1000h
mov cx, 24h
array: mov [bx], al
       add al, 50d
       inc bx
       loop array
mov bx, 1000h
mov al, [bx]
mov cx, 1fh
l1: cmp al, [bx+1]
    jnc l2
    mov al, [bx+1]
l2: inc bx
loop l1
mov [0fffh], al
hlt
ret
