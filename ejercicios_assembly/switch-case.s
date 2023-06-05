    CMP R0, #1       ; Compara el valor en R0 con 1
    BEQ case_1       ; Si es igual a 1, salta a case_1
    CMP R0, #2       ; Compara el valor en R0 con 2
    BEQ case_2       ; Si es igual a 2, salta a case_2
    CMP R0, #3       ; Compara el valor en R0 con 3
    BEQ case_3       ; Si es igual a 3, salta a case_3
    CMP R0, #4       ; Compara el valor en R0 con 4
    BEQ case_4       ; Si es igual a 4, salta a case_4
    B default_case   ; Si no se cumple ninguna de las condiciones anteriores, salta a default_case

case_1
    ; Código para el caso 1
    B end_switch     ; Salta al final del switch-case

case_2
    ; Código para el caso 2
    B end_switch     ; Salta al final del switch-case

case_3
    ; Código para el caso 3
    B end_switch     ; Salta al final del switch-case

case_4
    ; Código para el caso 4
    B end_switch     ; Salta al final del switch-case

default_case
    ; Código para el caso por defecto

end_switch
    ; Código después del switch-case
