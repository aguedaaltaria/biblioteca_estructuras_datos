#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <stdbool.h>

// 1. Nodo para el encadenamiento (chaining) de colisiones en la tabla hash
struct NodoHash {
    const char *clave;          // Clave de búsqueda (ej. "gilda")
    int valor;                  // Valor asociado (ej. 42)
    struct NodoHash *siguiente; // Puntero al siguiente elemento en caso de colisión
};

// 2. Estructura principal de la Tabla Hash
struct TablaHash {
    int capacidad;              // Número total de casilleros o cubetas (buckets)
    struct NodoHash **cubetas;  // Arreglo dinámico de punteros (cabeceras de listas)
};

// --- FÁBRICA Y GESTIÓN DE MEMORIA ---
struct TablaHash* crear_tabla_hash(int capacidad);
void liberar_tabla_hash(struct TablaHash *tabla);

// --- OPERACIONES FUNDAMENTALES ---
void insertar_en_tabla_hash(struct TablaHash *tabla, const char *clave, int valor);
int buscar_en_tabla_hash(struct TablaHash *tabla, const char *clave, bool *encontrado);
void eliminar_de_tabla_hash(struct TablaHash *tabla, const char *clave);

void imprimir_tabla_hash(struct TablaHash *tabla);

#endif