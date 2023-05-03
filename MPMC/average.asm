org 100h
array DB 10 dup(0)
array_size equ 10
mov cx, 10
mov bx, offset array
mov ah, 16D
mov dl, 0H ;sum
mov dh, 10D ; average 
next: mov al, [bx]                
      mov al, ah
      inc ah                  ; 
      mov [bx], al 
      add dl,al                 
      add bx,1                     
  loop next:  
mov ax, 0000h
mov al, dl
div dh

hlt
ret     
