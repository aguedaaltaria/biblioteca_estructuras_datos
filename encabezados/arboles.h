#ifndef ARBOLES_H
#define ARBOLES_H

// Estructura del nodo para un Árbol Binario de Búsqueda (BST)
struct NodoArbolBinario {
    int dato;
    struct NodoArbolBinario *izquierda;
    struct NodoArbolBinario *derecha;
};

// --- FÁBRICA Y GESTIÓN ---
struct NodoArbolBinario* crear_nodo_arbol(int valor);
struct NodoArbolBinario* insertar_en_arbol(struct NodoArbolBinario *raiz, int valor);
void liberar_arbol(struct NodoArbolBinario *raiz); // Utiliza recorrido Post-order internamente

// --- LOS TRES RECORRIDOS CLÁSICOS ---
void recorrer_in_order(struct NodoArbolBinario *raiz);   // Izquierda -> Raíz -> Derecha (Ordenado de menor a mayor)
void recorrer_pre_order(struct NodoArbolBinario *raiz);  // Raíz -> Izquierda -> Derecha (Ideal para clonar)
void recorrer_post_order(struct NodoArbolBinario *raiz); // Izquierda -> Derecha -> Raíz (Ideal para borrar)

// void generar_grafo_arbol(struct NodoArbolBinario *raiz, const char *nombre_archivo);
void exportar_a_dot(struct NodoArbolBinario *raiz, const char *nombre_archivo_dot, const char *nombre_imagen_png);

#endif