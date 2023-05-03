org 100h
array DW 15 dup(0)        ; define an array of 10 words and initialize its values to 0

mov cx, 15                ; initialize the loop counter to 11 (for values 16 to 26)
mov si, offset array      ; initialize the source index to the start of the array
                         ; initialize the first value of the array to 16
mov [si],00D
add si,2   
mov ax,00D
mov bx,01D 

loop_start: 
  mov dx,ax
  add ax,bx
  mov [si], ax  
  mov bx,dx          ; store the current value (in AX) into the current element of the array
  add si, 2               ; increment the source index to point to the next element (2 bytes per element)
              
  loop loop_start         ; decrement the loop counter and repeat until it reaches 0
  
  
  hlt
  ret
