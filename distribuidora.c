#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;

typedef struct Nodo
{
    Tarea Tarea;
    struct Nodo *Siguiente;
} Nodo;
int id = 1000;
Nodo *CrearListaVacia()
{

    return NULL;
}

Nodo *CrearNodo(char *descripcion, int duracion);
void CargarTareas(Nodo **pendientes);

void InsertaTarea(Nodo **lista, Nodo *nuevoNodo);

    int main()
{
    int opcion;
    Nodo *pendiente = CrearListaVacia();
    Nodo *realizada = CrearListaVacia();

    do
    {
        printf("1. Cargar tareas\n");
        printf("2. Marcar tarea como realizada\n");
        printf("3. Listar tareas\n");
        printf("4. Buscar tarea\n");
        printf("5. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
        {
            
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;

            default:
                break;
        }
    } while (opcion != 5);

    return 0;
}

Nodo *CrearNodo(char *descripcion, int duracion)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->Tarea.TareaID = id++;
    nuevoNodo->Tarea.Descripcion = descripcion;
    nuevoNodo->Tarea.Duracion = duracion;
    nuevoNodo->Siguiente = NULL;
    return nuevoNodo;
}

void CargarTareas(Nodo **pendientes){
    char seguir[10] = "s";
    while (strcmp(seguir, "s") == 0 || strcmp(seguir, "S") ==0 )
    {
        char desc[100];
        printf("Ingrese descripcion de la tarea:");
        gets(desc);

        char *descripcion = (char *)malloc(strlen(desc)+1);
        strcpy (descripcion, desc);
        int duracion ;
        printf("Ingrese la duracion de la Tares (10-100) :");
        scanf("%d", &duracion);

        fflush(stdin);

    }
    
}

void InsertaTarea(Nodo **lista, Nodo *nuevoNodo){
    nuevoNodo->Siguiente = *lista;
    *lista = nuevoNodo;
    
}