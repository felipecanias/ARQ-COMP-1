
.text

.global choque_asm
choque_asm:
      PUSH {R4, R5, LR}
      MOV R4, #7
      LDR R5, =array

loop:
    LDRB R0, [R5], #1
    BL disp_binary_asm
    
    
    BL delay_asm

    SUBS R4, R4, #1
    BNE loop

    POP {R4, R5, PC}

.data
array:
      .byte 0x81
      .byte 0x42
      .byte 0x24
      .byte 0x18
      .byte 0x18
      .byte 0x24
      .byte 0x42

.end
