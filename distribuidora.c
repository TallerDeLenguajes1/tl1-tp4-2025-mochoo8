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

void TransferirTarea(Nodo **pendientes, Nodo **realizada);

void ListarTareas(Nodo *lista);

void MostrarTarea(Tarea Tarea);

void BuscarTarea(Nodo *lista, int id);

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
                CargarTareas(&pendiente);
                printf("Tareas cargadas correctamente.\n");
                break;
            case 2:
                TransferirTarea(&pendiente, &realizada);
                printf("Tarea transferida correctamente.\n");
                break;
            case 3:
                ListarTareas(pendiente);
                ListarTareas(realizada);
               
                break;
            case 4:
                printf("Ingrese el ID de la tarea a buscar: ");
                int id;
                scanf("%d", &id);
                fflush(stdin);
                BuscarTarea(pendiente, id);
                BuscarTarea(realizada, id);
                printf("Tarea buscada correctamente.\n");

                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
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

        InsertaTarea(pendientes, CrearNodo(descripcion, duracion));
        printf("Desea agregar otra tarea? (s/n): ");
        gets(seguir);
        

    }
    
}

void InsertaTarea(Nodo **lista, Nodo *nuevoNodo){
    nuevoNodo->Siguiente = *lista;
    *lista = nuevoNodo;
}

void TransferirTarea(Nodo **pendientes, Nodo **realizada){
    int id;
    printf("Ingrese el ID de la tarea a transferir: ");
    scanf("%d", &id);
    fflush(stdin);
    Nodo *actual = *pendientes;
    Nodo *anterior = NULL;
    while (actual != NULL && actual->Tarea.TareaID != id)
    {
        anterior = actual;
        actual = actual->Siguiente;
    }
    if (actual == NULL)
    {
        printf("Tarea no encontrada.\n");
        return;
    }
    if (anterior == NULL)
    {
        *pendientes = actual->Siguiente;
    }
    else
    {
        anterior->Siguiente = actual->Siguiente;
    }
    InsertaTarea(realizada, actual);
    printf("Tarea transferida correctamente.\n");
    
}

void ListarTareas(Nodo *lista){
    Nodo *actual = lista;
    if (actual == NULL)
    {
        printf("No hay tareas pendientes.\n");
        return;
    }
    printf("Tareas pendientes:\n");
    while (actual != NULL)
    {
        MostrarTarea(actual->Tarea);
        actual = actual->Siguiente;
    }
}

void MostrarTarea(Tarea Tarea){
    printf("ID: %d\n", Tarea.TareaID);
    printf("Descripcion: %s\n", Tarea.Descripcion);
    printf("Duracion: %d\n", Tarea.Duracion);
}

void BuscarTarea(Nodo *lista, int id){
    Nodo *actual = lista;
    while (actual != NULL && actual->Tarea.TareaID != id)
    {
        actual = actual->Siguiente;
    }
    if (actual == NULL)
    {
        printf("Tarea no encontrada.\n");
        return;
    }
    MostrarTarea(actual->Tarea);
    printf("Tarea encontrada.\n");
    
}