
.text

.global auto_fantastico_asm

auto_fantastico_asm:
      PUSH {R4, R5, R6, LR}     //Guardo en pila por ser subrutina
      MOV R6, R0                //Guardo el delay en R6
      MOV R4, #0x80
      LDR R0, =name
      MOV R1, R6
      BL init_secuencia

loop:
    MOV R0, R4
    MOV R4, R4, LSR #1
    LDR R1, =name
    MOV R2, R6
    BL disp_binary

    CMP R4, #0
    MOVEQ R4, #0x01
    BEQ loop2

    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, PC}

    B loop

loop2:

    MOV R0, R4
    MOV R4, R4, LSL #1
    LDR R1, =name
    MOV R2, R6
    BL disp_binary

    CMP R4, #0x80
    BEQ loop

    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, PC}

    B loop2


.data
name:
	.asciz "Auto Fantastico"

.end

