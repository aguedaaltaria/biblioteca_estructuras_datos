#include <stdio.h>
#include <stdlib.h> // Aquí es donde vive la función malloc()
#include "../encabezados/lista_enlazada.h"

// Función que "fabrica" un nodo nuevo y nos devuelve la dirección (puntero) donde lo construyó
struct Nodo* crear_nodo(int valor_inicial) {
    
    // 1. Le pedimos a Linux que nos preste espacio en la memoria RAM.
    struct Nodo *nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    // 2. Regla de oro en C: Siempre verificar si la memoria se asignó correctamente.
    if (nuevo_nodo == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        return NULL;
    }

    // 3. Preparamos la casa nueva
    nuevo_nodo->dato = valor_inicial;
    nuevo_nodo->siguiente = NULL; // Al nacer, el nodo no está conectado a nadie

    // 4. Devolvemos la dirección de la casa nueva
    return nuevo_nodo;
}

// Función para insertar un nodo nuevo al inicio de la lista
struct Nodo* insertar_al_inicio(struct Nodo *cabeza_actual, int nuevo_valor) {
    struct Nodo *nuevo_nodo = crear_nodo(nuevo_valor);
    
    if (nuevo_nodo == NULL) {
        return cabeza_actual;
    }

    nuevo_nodo->siguiente = cabeza_actual;
    return nuevo_nodo;
}

// Función para recorrer e imprimir toda la lista enlazada
void recorrer_lista(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("\n--- Recorriendo la lista ---\n");
    struct Nodo *actual = cabeza; 
    
    while (actual != NULL) {
        printf("Nodo con el dato: %d\n", actual->dato);
        actual = actual->siguiente; 
    }
}

// Función para liberar toda la memoria de la lista de golpe
void liberar_lista(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza; 
    struct Nodo *siguiente_temporal;

    while (actual != NULL) {
        siguiente_temporal = actual->siguiente; 
        free(actual); 
        actual = siguiente_temporal; 
    }
}

// Función para insertar un nodo al final de la lista (Comportamiento FIFO / Cola)
struct Nodo* insertar_al_final(struct Nodo *cabeza, int nuevo_valor) {
    struct Nodo *nuevo_nodo = crear_nodo(nuevo_valor);
    if (nuevo_nodo == NULL) {
        return cabeza;
    }

    if (cabeza == NULL) {
        return nuevo_nodo;
    }

    struct Nodo *actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo_nodo;
    return cabeza;
}

// Función para buscar un valor en la lista. 
struct Nodo* buscar_nodo(struct Nodo *cabeza, int valor_buscado) {
    struct Nodo *actual = cabeza;

    while (actual != NULL) {
        if (actual->dato == valor_buscado) {
            return actual; 
        }
        actual = actual->siguiente;
    }

    return NULL;
}

// Función para eliminar un nodo específico por su valor
struct Nodo* eliminar_nodo(struct Nodo *cabeza, int valor_a_eliminar) {
    if (cabeza == NULL) {
        return NULL;
    }

    if (cabeza->dato == valor_a_eliminar) {
        struct Nodo *temp = cabeza;       
        cabeza = cabeza->siguiente;       
        free(temp);                       
        return cabeza;                    
    }

    struct Nodo *actual = cabeza;
    
    while (actual->siguiente != NULL && actual->siguiente->dato != valor_a_eliminar) {
        actual = actual->siguiente;
    }

    if (actual->siguiente != NULL) {
        struct Nodo *temp = actual->siguiente; 
        actual->siguiente = temp->siguiente;   
        free(temp);                            
    }

    return cabeza;
}

// Función para contar cuántos nodos forman parte de la lista
int obtener_longitud(struct Nodo *cabeza) {
    int contador = 0;
    struct Nodo *actual = cabeza;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

// Función para invertir el orden de toda la lista enlazada
struct Nodo* invertir_lista(struct Nodo *cabeza) {
    struct Nodo *previo = NULL;
    struct Nodo *actual = cabeza;
    struct Nodo *siguiente_temporal = NULL;

    while (actual != NULL) {
        siguiente_temporal = actual->siguiente;
        actual->siguiente = previo;
        previo = actual;
        actual = siguiente_temporal;
    }

    return previo;
}

// --- FUNCIONES DE LISTA DOBLE ---

// Función para fabricar un nodo doble en la memoria dinámica (Heap)
struct NodoDoble* crear_nodo_doble(int valor_inicial) {
    struct NodoDoble *nuevo_nodo = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
    
    if (nuevo_nodo == NULL) {
        printf("Error: No hay memoria suficiente para el nodo doble.\n");
        return NULL;
    }

    nuevo_nodo->dato = valor_inicial;
    nuevo_nodo->siguiente = NULL; 
    nuevo_nodo->anterior = NULL;  

    return nuevo_nodo;
}

// Función para insertar al inicio en una lista doble
struct NodoDoble* insertar_inicio_doble(struct NodoDoble *cabeza, int nuevo_valor) {
    struct NodoDoble *nuevo_nodo = crear_nodo_doble(nuevo_valor);
    if (nuevo_nodo == NULL) {
        return cabeza;
    }

    if (cabeza != NULL) {
        cabeza->anterior = nuevo_nodo;
        nuevo_nodo->siguiente = cabeza;
    }

    return nuevo_nodo;
}

// Función para recorrer una lista doble (hacia adelante y hacia atrás)
void recorrer_lista_doble(struct NodoDoble *cabeza) {
    if (cabeza == NULL) {
        printf("La lista doble está vacía.\n");
        return;
    }

    printf("\n--- Recorriendo lista doble (Hacia adelante) ---\n");
    struct NodoDoble *actual = cabeza;
    struct NodoDoble *ultimo = NULL;

    while (actual != NULL) {
        printf("Nodo con el dato: %d\n", actual->dato);
        ultimo = actual; 
        actual = actual->siguiente;
    }

    printf("\n--- Recorriendo lista doble (De regreso / Hacia atrás) ---\n");
    actual = ultimo;
    while (actual != NULL) {
        printf("Nodo con el dato: %d\n", actual->dato);
        actual = actual->anterior;
    }
}

// Función para liberar la memoria de una lista doble
void liberar_lista_doble(struct NodoDoble *cabeza) {
    struct NodoDoble *actual = cabeza;
    struct NodoDoble *siguiente_temporal;

    while (actual != NULL) {
        siguiente_temporal = actual->siguiente;
        free(actual);
        actual = siguiente_temporal;
    }
}