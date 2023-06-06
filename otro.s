
.text

.global otro_asm
otro_asm:
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

.end
