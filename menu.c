#include <stdio.h>

int main() {
  int menu;

  printf("---Menu---\n");
  printf("1) Caso 1\n");
  printf("2) Caso 2\n");
  printf("3) Caso 3\n");
  printf("4) Caso 4\n");
  printf("5) Exit\n\n");

  printf("Seleccione una opción: ");
  scanf("%d", &menu);

  switch (menu) {
    case 1:
        printf("\nMenu 1\n");
        break;
    case 2:
        printf("\nMenu 2\n");
        break;
    case 3:
        printf("\nMenu 3\n");
        break;
    case 4:
        printf("\nMenu 4\n");
        break;
    case 5:
        printf("\nExit\n");
        break;
    default:
        printf("\nOpción inválida\n");
        break;
  }

  return 0;
}
