.MODEL SMALL
.DATA
.CODE
BACK:
NEXT:
SKIP:
ARRAY DB 12H, -98H,-45H,83H,-28H, 67H, 92H, -54H, -63H, 76H NEGI DB 10 
DUP (?)
POSI DB 10 DUP (?)
MOV AX, @DATA               ; INITIALIZE THE DATA SEGMENT
MOV DS, AX
MOV CL, 0AH                 ; INITIALIZE THE COUNTER
XOR DI, DI                  ; INITIALIZE THE POINTER FOR NEGATIVE NUMBER
XOR SI, SI                  ; INITIALIZE THE POINTER FOR POSITIVE NUMBER
LEA BP, ARRAY
MOV AL, DS:[BP]             ; GET THE NUMBER
TEST AL, 80H                ; MASK ALL BITS EXCEPT MSB
JZ NEXT ; IF LSB = 0 GOT TO NEXT
LEA BX, NEGI
MOV [BX+DI], AL
INC DI                      ; INCREMENT THE NEGATIVE 
POINTER JMP SKIP
LEA BX, POSI
MOV [BX+SI], AL
INC SI                      ; INCREMENT THE POSITIVE POINTER
INC BP                      ; INCREMENT ARRAY BASE POINTER
LOOP BACK                   ; DECREMENT THE 
COUNTER MOV AH, 4CH
INT 21H
END                         ; END PROGRAM