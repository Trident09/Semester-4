org 100h
mov ax, 6000h
mov ds,ax
mov bx, 1000h
mov cx, 10h
 
mov ax,0000h
array:
    
    add ax, 3d  
    mov [bx],ax 
    inc bx
    inc bx  
loop array:   


mov bx,1000h
mov ax,[bx]
mov cx, 10h

l1:
   mov ax,[bx]
   ror ax,1
   jnc l2
   add [0700h],1d
l2:

   inc bx
   inc bx
   loop l1
 
mov  ax, 16d
sub ax,[0700h]    
mov [0710h],ax

hlt
ret
