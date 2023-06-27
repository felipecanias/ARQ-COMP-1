#include "password.c"
#include "menu.c"

int main() {
    initscr(); // Inicializar la biblioteca ncurses
    cbreak(); // Desactivar el búfer de línea (lectura de caracteres uno por uno)
    noecho(); // No mostrar los caracteres ingresados

    start_color();
    // Habilitar el uso de colores
    if (has_colors() == FALSE) {
        endwin();
        printf("Tu terminal no soporta colores\n");
        return 1;
    }
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    if (login()) menu(); //Intentamos el logeo

    endwin(); // Finalizar la biblioteca ncurses
    return 0;
}
