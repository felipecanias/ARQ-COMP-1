
.text

.global carrera_asm
carrera_asm:
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
    CMP R4, #16
    BNE loop
    MOVEQ R4, #0
    B loop



.data
array:
       .byte 0x01
       .byte 0x01
       .byte 0x02
       .byte 0x02
       .byte 0x04
       .byte 0x04
       .byte 0x08
       .byte 0x08
       .byte 0x11
       .byte 0x12
       .byte 0x24
       .byte 0x28
       .byte 0x50
       .byte 0x60
       .byte 0xC0
       .byte 0x80

name:
	.asciz "La Carrera"

.end

