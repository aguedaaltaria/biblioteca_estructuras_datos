#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

// Estructura del Min-Heap (arreglo plano con aritmética de índices)
struct Heap {
    int *datos;       // Arreglo contiguo en memoria
    int capacidad;    // Capacidad máxima reservada
    int tamanio;      // Elementos actuales ocupados
};

// --- API del Min-Heap ---
struct Heap* crear_heap(int capacidad);
void liberar_heap(struct Heap *heap);
bool insertar_en_heap(struct Heap *heap, int valor);
int extraer_min_heap(struct Heap *heap, bool *exito);

#endif