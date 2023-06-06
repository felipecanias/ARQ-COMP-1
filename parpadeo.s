.text

.global parpadeo_estelar_asm
parpadeo_estelar_asm:
    PUSH {R4, R5, LR}
    MOV R4, #16
    MOV R5, #0x80

loop:
    BL disp_binary_asm

    BL delay_asm

    CMP R5, #0x01
    BEQ end_loop

    MOV R6, R5, LSR #1
    MOV R7, R5, LSL #1
    ORR R5, R6, R7

    SUBS R4, R4, #1
    BNE loop

end_loop:
    POP {R4, R5, PC}
