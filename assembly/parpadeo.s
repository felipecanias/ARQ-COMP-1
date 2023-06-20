
.text

.global parpadeo_estelar_asm

parpadeo_estelar_asm:
      PUSH {R4, R5, R6, LR}     //Guardo en pila por ser subrutina
      MOV R6, R0                //Guardo el delay en R6
      MOV R4, #0x80
      MOV R5, #1

loop:
    CMP R5, #1

    MOVEQ R0, R4
    MOVEQ R5, #0
    MOVEQ R4, R4, LSR #1

    MOVNE R0, #0x00
    MOVNE R5, #1

    LDR R1, =name
    MOV R2, R6
    BL disp_binary

    CMP R4, #0
    MOVEQ R4, #0x01
    MOVEQ R5, #1
    BEQ loop2

    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, PC}

    B loop

loop2:
    CMP R5, #1

    MOVEQ R0, R4
    MOVEQ R5, #0
    MOVEQ R4, R4, LSL #1

    MOVNE R0, #0x00
    MOVNE R5, #1

    LDR R1, =name
    MOV R2, R6
    BL disp_binary

    CMP R4, #0x80
    MOVEQ R5, #1
    BEQ loop

    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, PC}

    B loop2


.data
name:
	.asciz "Parpadeo Estelar"

.end

