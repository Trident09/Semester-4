ORG 100h

NUMBER DW 11 DUP(0) ; Define an array of 20 words, initialized to 0

MOV BX,OFFSET NUMBER ; Load BX with the address of the array
MOV CX,11 ; Set CX to the number of elements in the array

NEXT:
  MOV AL,[BX] ; Load the current element of the array into AL
  INC AL ; Increment the value in AL by 1        
  MOV [BX],AL ; Store the updated value back into the array
  ADD BX,1 ; Increment BX by 1 to point to the next element of the array 8(since each element is a word)
LOOP NEXT

RET

