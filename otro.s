
.text

.global otro_asm
otro_asm:
      PUSH {R4, R5, R6, R7, LR}     //Guardo en pila por ser subrutina
      MOV R4, #0                //Contador
      LDR R5, =array            //Cargo el Array
      MOV R6, R0                //Guardo el delay en R6

loop:
    LDRB R0, [R5, R4]
    LDR R1, =name
    MOV R2, R6
    BL disp_binary
    
    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, R7, PC}

    ADD R4, R4, #1
    CMP R4, #14
    BNE loop
    MOVEQ R4, #0
    B loop



.data
array:
       .byte 0x00
       .byte 0x80
       .byte 0xC0
       .byte 0x60
       .byte 0x61
       .byte 0x62
       .byte 0x52
       .byte 0x4A
       .byte 0x46
       .byte 0x43
       .byte 0x41
       .byte 0x40
       .byte 0x80
       .byte 0x00

name:
	.asciz "Ella se fue con otro"

.end

