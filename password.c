#include <ncurses.h>

bool login() {

    char password[] = "54321";
    char password_input[5];

    for (int i = 0; i < 3; i++) {
        clear();
        printw("Ingrese su password de 5 dígitos: ");
        refresh();
        //Ingreso de Password
        for (int i = 0; i < 5; ++i) {
            password_input[i] = getch();
            printw("*");
            refresh();
        }
        //Comparacion char a char
        bool login_success = false;
        for (int j = 0; j < 5; j++) {
            if (password[j] != password_input[j]){
                //Passwords no iguales
                clear();
                printw("Password no valida\n");
                printw("Intentos disponibles: %d\n", 3-(i+1));
                printw("Presione cualquier tecla para continuar\n");
                refresh();
                getch();
                login_success = false;
                break;
            } else login_success = true;
        }
        //Passwords iguales, login exitoso
        if(login_success) {
            printw("\nBienvenido al Sistema\n");
            printw("Enviando mensaje por telegram...\n");
            refresh();
            clear();
            return 1;
        }
    }
    return 0;

}
