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