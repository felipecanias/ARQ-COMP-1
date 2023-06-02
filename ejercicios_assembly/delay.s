retardo
    CMP R0, #0       ; Compara el valor de a con cero
    BEQ fin_retardo  ; Salta a fin_retardo si a es igual a cero
loop
    SUBS R0, R0, #1  ; Resta 1 a r0
    BNE loop         ; Salta a loop si r0 no es igual a cero
fin_retardo
    MOV PC, LR       ; Regresa al llamador
