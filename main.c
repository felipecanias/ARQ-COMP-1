#include "password.c"
#include "menu.c"

int main() {
    initscr(); // Inicializar la biblioteca ncurses
    cbreak(); // Desactivar el búfer de línea (lectura de caracteres uno por uno)
    noecho(); // No mostrar los caracteres ingresados
    getch();
    if (login()) menu(); //Intentamos el logeo

    endwin(); // Finalizar la biblioteca ncurses
    return 0;
}