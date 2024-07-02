#include "inventario.h"

FILE *fp;

void crear(int n) {
  srand(time(NULL));
  struct info producto;
  producto.codigo = rand() % 100001;

  char productos[] = "Factura.txt";
  fp = fopen(productos, "w+");

  if (fp == NULL) {
    printf("Error al abrir el archivo");
    exit(1);
  }

  fprintf(fp, "\t::::::Inventario::::::\n");
  fprintf(fp, "\t#\t\tCodigo\t\tDescripcion\t\tIngresos\t\tSalidas\t\tStock\n");

  fflush(stdin);
  printf("Producto: ");
  scanf("%s", producto.nombre);
  printf("Ingresos: ");
  scanf("%d", &producto.ingreso);
  printf("Salidas: ");
  scanf("%d", &producto.salida);

  fprintf(fp, "\t%d\t\t", n);
  fprintf(fp, "%d\t\t\t", producto.codigo);
  fwrite(producto.nombre, 1, strlen(producto.nombre), fp);
  fprintf(fp, "\t\t\t%d\t\t\t%d\t\t\t%d\n\n", producto.ingreso, producto.salida,
          producto.stock = producto.ingreso - producto.salida);

  fclose(fp);
}

int agregar(int n) {
  struct info producto;
  int opc = 1;
  char productos[] = "Factura.txt";
  fp = fopen(productos, "a");

  if (fp == NULL) {
    printf("Error al abrir el archivo");
    exit(1);
  }

  do {
    srand(time(NULL));
    producto.codigo = rand() % 100001;
    fflush(stdin);
    printf("Producto: ");
    scanf("%s", producto.nombre);
    printf("Ingresos: ");
    scanf("%d", &producto.ingreso);
    printf("Salidas: ");
    scanf("%d", &producto.salida);

    fprintf(fp, "\t%d\t\t", n);
    fprintf(fp, "%d\t\t\t", producto.codigo);
    fwrite(producto.nombre, 1, strlen(producto.nombre), fp);
    fprintf(fp, "\t\t\t%d\t\t\t%d\t\t\t%d\n\n", producto.ingreso,
            producto.salida,
            producto.stock = producto.ingreso - producto.salida);

    printf("Desea ingresar otro producto? (Si = 1/ No = 0): ");
    scanf("%d", &opc);
    n++;
  } while (opc == 1);

  fclose(fp);
  return n;
}

void borrar(int numeroProducto) {
  char arch_temp[] = "temp.txt";
  fp = fopen("Factura.txt", "r");
  FILE *temp = fopen(arch_temp, "w");

  if (fp == NULL || temp == NULL) {
    printf("Error al abrir el archivo");
    exit(1);
  }

  char linea[1000];
  int lineaActual = 0;
  int coincidencia = 0;

  while (fgets(linea, sizeof(linea), fp)) {
    if (lineaActual < 2 || (lineaActual - 2) != numeroProducto) {
      fputs(linea, temp);
    } else {
      coincidencia = 1;
    }
    lineaActual++;
  }

  if (!coincidencia) {
    printf("No se encontró el producto número %d\n", numeroProducto);
  } else {
    remove("Factura.txt");
    rename(arch_temp, "Factura.txt");
    printf("Producto número %d ha sido eliminado correctamente.\n",
           numeroProducto);
  }

  fclose(fp);
  fclose(temp);
}

void mostrar() {
  char c;
  char productos[] = "Factura.txt";
  fp = fopen(productos, "r");

  if (fp == NULL) {
    printf("Error al abrir el archivo");
    exit(1);
  }

  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      printf("\n");
    } else {
      putchar(c);
    }
  }

  fclose(fp);
}