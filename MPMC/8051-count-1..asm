ORG 0x0000

MAIN:
    MOV A, #0
    MOV R0, #8
    
LOOP:
    MOV C, A
    RRC A
    
    JC INCREMENT
    
DECREMENT:
    DJNZ R0, LOOP
    SJMP EXIT
    
INCREMENT:
    INC A
    JMP DECREMENT
    
EXIT:
    
END
