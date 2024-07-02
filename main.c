#include "inventario.h"

int main() {
  int opc;
  int n = 1;
  int numeroProducto;

  do {
    printf("\n\t::::::MENU::::::\n");
    printf("\n1. Crear y agregar un producto");
    printf("\n2. Agregar más productos");
    printf("\n3. Visualizar productos registrados hasta el momento");
    printf("\n4. Eliminar producto");
    printf("\n5. Salir");
    printf("\nOpcion : ");
    scanf("%d", &opc);

    switch (opc) {
    case 1:
      crear(n);
      n++;
      break;
    case 2:
      if (n > 1) {
        n = agregar(n);
      } else {
        printf("Primero debe crear al menos un producto usando la opcion 1.\n");
      }
      break;
    case 3:
      mostrar();
      break;
    case 4:
      if (n > 1) {
        printf("Ingrese el numero del producto que desea eliminar:\n");
        scanf("%d", &numeroProducto);
        borrar(numeroProducto);
      } else {
        printf("Primero debe crear al menos un producto usando la opcion 1.\n");
      }
      break;
    case 5:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
  } while (opc != 5);

  return 0;
}