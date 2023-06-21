
.text

.global choque_asm
choque_asm:
      PUSH {R4, R5, R6, LR}     //Guardo en pila por ser subrutina
      MOV R4, #0                //Contador
      LDR R5, =array            //Cargo el Array
      MOV R6, R0                //Guardo el delay en R6
      LDR R0, =name
      MOV R1, R6
      BL init_secuencia

loop:
    LDRB R0, [R5, R4]
    LDR R1, =name
    MOV R2, R6
    BL disp_binary
    
    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, PC}

    ADD R4, R4, #1
    CMP R4, #7
    BNE loop
    MOVEQ R4, #0
    B loop



.data
array:
       .byte 0x81
       .byte 0x42
       .byte 0x24
       .byte 0x18
       .byte 0x18
       .byte 0x24
       .byte 0x42


name:
	.asciz "El Choque"

.end

