#include <stdio.h>
#include <stdlib.h>
#include "../encabezados/heap.h"

// Fábrica: Construye el contenedor y reserva el arreglo plano
struct Heap* crear_heap(int capacidad) {
    if (capacidad <= 0) {
        printf("Error: La capacidad del heap debe ser mayor a 0.\n");
        return NULL;
    }

    // 1. Reservar memoria para la estructura contenedora (metadatos)
    struct Heap *heap = (struct Heap*)malloc(sizeof(struct Heap));
    if (heap == NULL) {
        printf("Error: Sin memoria para la estructura principal del heap.\n");
        return NULL;
    }

    // 2. Reservar memoria para el arreglo plano de enteros
    heap->datos = (int*)malloc(sizeof(int) * capacidad);
    if (heap->datos == NULL) {
        printf("Error: Sin memoria para el arreglo de datos del heap.\n");
        free(heap); // ¡Higiene de C: liberamos la estructura si el arreglo falló!
        return NULL;
    }

    // 3. Inicializar el estado inicial
    heap->capacidad = capacidad;
    heap->tamanio = 0; // Arranca vacío (sin elementos guardados)

    return heap;
}

// Destructor: Limpia la memoria de adentro hacia afuera
void liberar_heap(struct Heap *heap) {
    if (heap == NULL) return; // Guardia contra punteros nulos

    free(heap->datos); // 1. Liberamos primero la memoria interna (el arreglo)
    free(heap);        // 2. Liberamos después el contenedor principal
}

// Inserta un valor y lo hace "flotar" si rompe la regla del Min-Heap
bool insertar_en_heap(struct Heap *heap, int valor) {
    if (heap == NULL) return false;

    // 1. Verificar si hay espacio (si el vaso está lleno)
    if (heap->tamanio >= heap->capacidad) {
        printf("Error: El heap alcanzó su capacidad máxima.\n");
        return false;
    }

    // 2. Colocar el valor nuevo exactamente al final del bloque ocupado
    int indice_actual = heap->tamanio;
    heap->datos[indice_actual] = valor;
    heap->tamanio++; // ¡Ahora hay un elemento más válido!

    // 3. Flotar hacia arriba (Heapify-up)
    while (indice_actual > 0) {
        int indice_padre = (indice_actual - 1) / 2;

        // Si mi valor es MENOR que el de mi padre, rompemos la regla Min-Heap
        if (heap->datos[indice_actual] < heap->datos[indice_padre]) {
            // Intercambiar (swap tradicional con auxiliar)
            int temporal = heap->datos[indice_actual];
            heap->datos[indice_actual] = heap->datos[indice_padre];
            heap->datos[indice_padre] = temporal;

            // Ahora subimos el foco al índice del padre para seguir revisando hacia arriba
            indice_actual = indice_padre;
        } else {
            // El padre es menor o igual, la regla se cumple. ¡Paramos!
            break;
        }
    }

    return true;
}

// Extrae la raíz (el mínimo), reorganiza el árbol hundiendo el último elemento (*heapify-down*)
int extraer_min_heap(struct Heap *heap, bool *exito) {
    if (heap == NULL || heap->tamanio == 0) {
        printf("Error: Intentando extraer de un heap nulo o vacío.\n");
        if (exito != NULL) *exito = false;
        return 0; // Valor centinela de error
    }

    // 1. El valor a retornar es siempre la raíz
    int valor_minimo = heap->datos[0];

    // 2. Tomar el último elemento ocupado y ponerlo temporalmente en la raíz
    heap->tamanio--;
    
    // Si todavía quedan elementos en el heap, debemos reacomodar (hundir)
    if (heap->tamanio > 0) {
        heap->datos[0] = heap->datos[heap->tamanio];

        int indice_actual = 0;

        // 3. Hundir hacia abajo (Heapify-down)
        while (true) {
            int indice_izquierdo = 2 * indice_actual + 1;
            int indice_derecho   = 2 * indice_actual + 2;
            int indice_menor     = indice_actual;

            // Comparar con el hijo izquierdo si existe dentro de los límites válidos
            if (indice_izquierdo < heap->tamanio && 
                heap->datos[indice_izquierdo] < heap->datos[indice_menor]) {
                indice_menor = indice_izquierdo;
            }

            // Comparar con el hijo derecho si existe dentro de los límites válidos
            if (indice_derecho < heap->tamanio && 
                heap->datos[indice_derecho] < heap->datos[indice_menor]) {
                indice_menor = indice_derecho;
            }

            // Si el menor de los tres sigue siendo el actual, la regla se cumple. ¡Paramos!
            if (indice_menor == indice_actual) {
                break;
            }

            // Intercambiar con el hijo que ganó ser el menor
            int temporal = heap->datos[indice_actual];
            heap->datos[indice_actual] = heap->datos[indice_menor];
            heap->datos[indice_menor] = temporal;

            // Actualizar el índice para seguir bajando en el siguiente nivel
            indice_actual = indice_menor;
        }
    }

    if (exito != NULL) *exito = true;
    return valor_minimo;
}