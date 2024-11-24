#include <stdio.h>
#include "funciones.h"

int main() {
    int numProductos;
    char materiales[MAX_PRODUCTOS][MAX_MATERIALES][MAX_NOMBRE];
    int requeridos[MAX_PRODUCTOS][MAX_MATERIALES];
    int disponibles[MAX_PRODUCTOS][MAX_MATERIALES];
    int numMateriales[MAX_PRODUCTOS];

    char entradaNumProductos[10];
    printf("Ingrese la cantidad de productos: ");
    scanf("%s", entradaNumProductos);

    while (!esNumeroValido(entradaNumProductos)) {
        printf("Por favor, ingrese un número válido: ");
        scanf("%s", entradaNumProductos);
    }
    numProductos = convertirACadenaNumerica(entradaNumProductos);

    for (int i = 0; i < numProductos; i++) {
        printf("\nProducto %d:\n", i + 1);
        ingresarMateriales(materiales[i], requeridos[i], &numMateriales[i]);
        ingresarDisponibilidad(materiales[i], disponibles[i], numMateriales[i]);

        int opcion;
        do {
            printf("\n¿Qué desea hacer?\n");
            printf("1. Editar un material\n");
            printf("2. Eliminar un material\n");
            printf("3. Continuar al siguiente producto\n");
            printf("Seleccione una opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    editarMaterial(materiales[i], requeridos[i], disponibles[i], numMateriales[i]);
                    break;
                case 2:
                    eliminarMaterial(materiales[i], requeridos[i], disponibles[i], &numMateriales[i]);
                    break;
                case 3:
                    printf("Pasando al siguiente producto...\n");
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
            }
        } while (opcion != 3);
    }

    for (int i = 0; i < numProductos; i++) {
        printf("\nReporte para el Producto %d:\n", i + 1);
        mostrarEstadoMateriales(materiales[i], requeridos[i], disponibles[i], numMateriales[i]);
    }

    printf("\nGracias por usar el programa.\n");
    return 0;
}