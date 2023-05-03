ORG 100H
       MOV AX, 6000H;
       MOV DS, AX;
       MOV AX, 30H;
       MOV BX, 1000H;
       MOV CX, 24H;
ARRAY: MOV [BX], AX;
       ADD AX, 50D;
       INC BX;
       LOOP ARRAY;
       MOV BX, 1000H;
       MOV AX, [BX];
       MOV CX, 1FH;
L1: CMP AX, [BX+2];
       JNC L2
       MOV AX, [BX+2]
L2: INC BX;
       LOOP L1;
       MOV [0FFFH], AX
       HLT
