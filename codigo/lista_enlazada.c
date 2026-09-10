#include <stdio.h>
#include <stdlib.h> // ¡NUEVO! Aquí es donde vive la función malloc()
#include "../encabezados/lista_enlazada.h"

// Función que "fabrica" un nodo nuevo y nos devuelve la dirección (puntero) donde lo construyó
struct Nodo* crear_nodo(int valor_inicial) {
    
    // 1. Le pedimos a Linux que nos preste espacio en la memoria RAM.
    // sizeof(struct Nodo) calcula exactamente cuántos bytes necesita nuestra casa.
    struct Nodo *nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    // 2. Regla de oro en C: Siempre verificar si la memoria se asignó correctamente.
    // Si la RAM de la compu estuviera llena, malloc devuelve NULL (nada).
    if (nuevo_nodo == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        return NULL;
    }

    // 3. Preparamos la casa nueva (usamos -> porque nuevo_nodo es un puntero/dirección)
    nuevo_nodo->dato = valor_inicial;
    nuevo_nodo->siguiente = NULL; // Al nacer, el nodo no está conectado a nadie

    // 4. Devolvemos el "papelito" con la dirección de la casa nueva
    return nuevo_nodo;
}

// Función para insertar un nodo nuevo al inicio de la lista
// Recibe la cabeza actual (el inicio de la lista) y el nuevo valor a guardar
struct Nodo* insertar_al_inicio(struct Nodo *cabeza_actual, int nuevo_valor) {
    
    // 1. Usamos nuestra propia fábrica para crear la casa nueva
    struct Nodo *nuevo_nodo = crear_nodo(nuevo_valor);
    
    // Si la fábrica falló (no hay memoria), devolvemos la lista como estaba
    if (nuevo_nodo == NULL) {
        return cabeza_actual;
    }

    // 2. Conectamos: El "siguiente" del nuevo nodo será la antigua cabeza de la lista
    nuevo_nodo->siguiente = cabeza_actual;

    // 3. El nuevo nodo es ahora la nueva cabeza oficial de la lista
    return nuevo_nodo;
}

// Función para recorrer e imprimir toda la lista enlazada
// Recibe la cabeza (el inicio de la lista) y se encarga de viajar y mostrar los datos
void recorrer_lista(struct Nodo *cabeza) {
    // Si la lista está vacía, avisamos y salimos
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
    // 1. Creamos la casa nueva con nuestra fábrica
    struct Nodo *nuevo_nodo = crear_nodo(nuevo_valor);
    if (nuevo_nodo == NULL) {
        return cabeza;
    }

    // 2. CASO ESPECIAL: Si la lista está vacía, el nuevo nodo es la flamante cabeza
    if (cabeza == NULL) {
        return nuevo_nodo;
    }

    // 3. CASO GENERAL: Si hay elementos, recorremos hasta encontrar el último nodo
    struct Nodo *actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente; // El taxi avanza hasta el último eslabón
    }

    // 4. Conectamos el último nodo con nuestro nuevo nodo
    actual->siguiente = nuevo_nodo;

    // 5. Devolvemos la cabeza original (porque el inicio de la lista nunca cambió)
    return cabeza;
}

// Función para buscar un valor en la lista. 
// Devuelve el puntero al nodo si lo encuentra, o NULL si no existe.
struct Nodo* buscar_nodo(struct Nodo *cabeza, int valor_buscado) {
    struct Nodo *actual = cabeza;

    // Recorremos la lista mientras no lleguemos al final
    while (actual != NULL) {
        // Si el dato de la casa actual coincide con lo que buscamos, ¡lo encontramos!
        if (actual->dato == valor_buscado) {
            return actual; 
        }
        // Si no, el taxi avanza al siguiente nodo
        actual = actual->siguiente;
    }

    // Si el bucle terminó y no lo encontró, devolvemos NULL
    return NULL;
}

// Función para eliminar un nodo específico por su valor
struct Nodo* eliminar_nodo(struct Nodo *cabeza, int valor_a_eliminar) {
    // Si la lista está vacía, no hay nada que borrar
    if (cabeza == NULL) {
        return NULL;
    }

    // CASO 1: El nodo a eliminar es la cabeza (el primer elemento)
    if (cabeza->dato == valor_a_eliminar) {
        struct Nodo *temp = cabeza;       // Guardamos temporalmente la cabeza vieja
        cabeza = cabeza->siguiente;       // La nueva cabeza pasa a ser la siguiente
        free(temp);                       // Demolemos la casa vieja
        return cabeza;                    // Devolvemos la nueva cabeza oficial
    }

    // CASO 2: El nodo está en el medio o al final
    struct Nodo *actual = cabeza;
    
    // Buscamos al nodo ANTERIOR al que queremos eliminar
    while (actual->siguiente != NULL && actual->siguiente->dato != valor_a_eliminar) {
        actual = actual->siguiente;
    }

    // Si encontramos el nodo (significa que actual->siguiente no es NULL)
    if (actual->siguiente != NULL) {
        struct Nodo *temp = actual->siguiente; // Guardamos el nodo a eliminar
        
        // RECONEXIÓN DE LA CARRETERA: El anterior salta al que estaba después del objetivo
        actual->siguiente = temp->siguiente;   
        
        free(temp);                            // Demolemos el nodo objetivo con seguridad
    }

    // Devolvemos la cabeza (que sigue siendo la misma, a menos que fuera el Caso 1)
    return cabeza;
}