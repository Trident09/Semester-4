;write a assembly code to move two values at memory location 1256H and 8976H.
;Then move the contents of these memory location to AX and BX registers.
;Then store the results of their addition , subtraction and multiplication to memory locations 2345 , 2347 and 2349 respectively.

org 100h

mov [1256H], 00010H
mov [8976H], 00001H   

mov ax,[1256H]
mov bx,[8976H] 

add ax,bx
mov [2345H], ax 


mov ax,[1256H] 
sub ax,bx   
mov [2347H], ax 

mov ax,[1256H]
mul bx;
mov [2349H],ax

hlt

ret
 
