#define MAX_PRODUCTOS 10
#define MAX_MATERIALES 10
#define MAX_NOMBRE 50

// Prototipos de funciones principales
void ingresarMateriales(char materiales[][MAX_NOMBRE], int requeridos[], int *numMateriales);
void ingresarDisponibilidad(char materiales[][MAX_NOMBRE], int disponibles[], int numMateriales);
void mostrarEstadoMateriales(char materiales[][MAX_NOMBRE], int requeridos[], int disponibles[], int numMateriales);
void editarMaterial(char materiales[][MAX_NOMBRE], int requeridos[], int disponibles[], int numMateriales);
void eliminarMaterial(char materiales[][MAX_NOMBRE], int requeridos[], int disponibles[], int *numMateriales);

// Validaciones
int esNumeroValido(char *str);
int convertirACadenaNumerica(char *str);

