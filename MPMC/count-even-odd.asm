.MODEL SMALL
.DATA
.CODE
BACK:
NEXT:
SKIP:
ARRAY DB 12H, 98H, 45H, 83H, 28H, 67H, 92H, 54H, 63H, 76H ARR_EVEN DB 
10 DUP (?)
ARR_ODD DB 10 DUP (?)
MOV AX, @DATA      ; INITIALIZE THE DATA SEGMENT
MOV DS, AX
MOV CL, 0AH        ; INITIALIZE THE COUNTER
XOR DI, DI         ; INITIALIZE THE ODD POINTER
XOR SI, SI         ; INITIALIZE THE EVEN POINTER
LEA BP, ARRAY
MOV AL, DS:[BP]    ; GET THE NUMBER
TEST AL, 01H ; MASK ALL BITS EXCEPT LSB
JZ NEXT ; IF LSB = 0 GOT TO NEXT
LEA BX, ARR_ODD
MOV [BX+DI], AL
INC DI              ; INCREMENT THE ODD 
POINTER JMP SKIP
LEA BX, ARR_EVEN
MOV [BX+SI], AL
INC SI              ; INCREMENT THE EVEN POINTER
INC BP              ; INCREMENT ARRAY BASE POINTER
LOOP BACK           ; DECREMENT THE 
COUNTER MOV AH, 4CH
INT 21H
END                 ; END PROGRAM