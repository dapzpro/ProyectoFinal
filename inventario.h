#define INVENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura para la información de los productos
struct info {
  int ingreso;      // Cantidad de productos ingresados
  int salida;       // Cantidad de productos vendidos
  int stock;        // Stock actual del producto
  int codigo;       // Código único del producto
  char nombre[100]; // Nombre del producto
};

// Declaración de funciones
void crear(int n);
int agregar(int n);
void borrar(int numeroProducto);
void mostrar();