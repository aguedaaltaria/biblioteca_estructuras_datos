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