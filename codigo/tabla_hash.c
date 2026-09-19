#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../encabezados/tabla_hash.h"

// Función auxiliar (static): convierte un texto en un número de índice válido dentro de la tabla.
static int calcular_indice_hash(const char *clave, int capacidad) {
    unsigned int suma_ascii = 0;
    
    // Recorremos letra por letra hasta el fin de la cadena ('\0')
    int indice_caracter = 0;
    while (clave[indice_caracter] != '\0') {
        suma_ascii = suma_ascii + (unsigned int)clave[indice_caracter];
        indice_caracter++;
    }
    
    // Operador módulo (%) asegura que el resultado nunca rebase la capacidad de la tabla
    int indice_en_la_tabla = (int)(suma_ascii % (unsigned int)capacidad);
    
    return indice_en_la_tabla;
}

// Fábrica para crear una tabla hash con 'capacidad' cubetas
struct TablaHash* crear_tabla_hash(int capacidad) {
    // 1. Reservamos memoria para la estructura principal de la tabla
    struct TablaHash *nueva_tabla = (struct TablaHash*)malloc(sizeof(struct TablaHash));
    if (nueva_tabla == NULL) {
        printf("Error: No hay memoria suficiente para la estructura de la tabla hash.\n");
        return NULL;
    }

    nueva_tabla->capacidad = capacidad;

    // 2. Reservamos memoria para el arreglo de punteros (las cubetas)
    // Cada celda de este arreglo va a guardar un "struct NodoHash*"
    nueva_tabla->cubetas = (struct NodoHash**)malloc(sizeof(struct NodoHash*) * capacidad);
    if (nueva_tabla->cubetas == NULL) {
        printf("Error: No hay memoria suficiente para el arreglo de cubetas.\n");
        free(nueva_tabla);
        return NULL;
    }

    // 3. Inicializamos cada casillero del arreglo apuntando a NULL (lista vacía)
    for (int i = 0; i < capacidad; i++) {
        nueva_tabla->cubetas[i] = NULL;
    }

    return nueva_tabla;
}

// Libera toda la memoria de la tabla hash (cubetas + listas de colisiones + estructura)
void liberar_tabla_hash(struct TablaHash *tabla) {
    if (tabla == NULL) {
        return;
    }

    // Recorremos cada casillero/cubeta del arreglo
    for (int i = 0; i < tabla->capacidad; i++) {
        struct NodoHash *nodo_actual = tabla->cubetas[i];
        
        // Si hay una lista enlazada en esta cubeta, la recorremos y liberamos
        while (nodo_actual != NULL) {
            struct NodoHash *nodo_siguiente = nodo_actual->siguiente;
            free(nodo_actual);
            nodo_actual = nodo_siguiente;
        }
    }

    // Liberamos el arreglo dinámico de cubetas
    free(tabla->cubetas);

    // Liberamos la estructura principal
    free(tabla);
}

// Inserta o encadena un par clave-valor en la tabla hash (Estrategia: Chaining / Inserción al frente O(1))
void insertar_en_tabla_hash(struct TablaHash *tabla, const char *clave, int valor) {
    // --- 1. Guardián de seguridad: evitamos Segmentation Fault por punteros nulos ---
    if (tabla == NULL || clave == NULL) {
        printf("Error: Tabla o clave nula al intentar insertar.\n");
        return;
    }

    // --- 2. Obtenemos el número de casillero (ej: 0 a 9) usando la función hash con % ---
    int indice = calcular_indice_hash(clave, tabla->capacidad);

    // --- 3. Reservamos memoria en el Heap para el nuevo nodo ---
    struct NodoHash *nuevo_nodo = (struct NodoHash*)malloc(sizeof(struct NodoHash));
    if (nuevo_nodo == NULL) {
        printf("Error: No hay memoria suficiente para el nodo hash.\n");
        return;
    }

    // --- 4. Asignamos la etiqueta (clave) y la información (valor) ---
    nuevo_nodo->clave = clave;
    nuevo_nodo->valor = valor;

    // --- 5. Estrategia de Encadenamiento (Chaining al frente / prepend) ---
    // El nuevo nodo se coloca ANTES de lo que ya estaba en este casillero.
    // Su 'siguiente' apunta a la antigua cabeza de la lista (o NULL si el casillero estaba vacío).
    nuevo_nodo->siguiente = tabla->cubetas[indice];
    
    // El casillero actualiza su puntero principal para que la cabeza sea este nuevo nodo.
    tabla->cubetas[indice] = nuevo_nodo;
}

// Busca un valor usando su clave. Usa bool *encontrado para reportar éxito/fracaso sin ambigüedad.
int buscar_en_tabla_hash(struct TablaHash *tabla, const char *clave, bool *encontrado) {
    // --- 1. Guardianes de seguridad contra punteros nulos ---
    if (tabla == NULL || clave == NULL || encontrado == NULL) {
        if (encontrado != NULL) {
            *encontrado = false;
        }
        return 0;
    }

    // Por defecto asumimos que no está
    *encontrado = false;

    // --- 2. Calculamos a qué casillero (índice) pertenece la clave ---
    int indice = calcular_indice_hash(clave, tabla->capacidad);

    // --- 3. Nos posicionamos en la cabeza de la lista enlazada de ese casillero ---
    struct NodoHash *actual = tabla->cubetas[indice];

    // --- 4. Recorremos la cadena de colisiones buscando coincidencia exacta de la clave ---
    while (actual != NULL) {
        // strcmp devuelve 0 exacto si las cadenas son iguales
        if (strcmp(actual->clave, clave) == 0) {
            *encontrado = true;
            return actual->valor; // ¡Encontrado! Retornamos el valor asociado
        }
        actual = actual->siguiente; // Avanzamos al siguiente nodo de la lista del casillero
    }

    // Si la lista terminó y no coincidió ninguna clave, no existe
    return 0; 
}

// Elimina un nodo clave-valor de la tabla hash buscando en la lista enlazada del casillero
void eliminar_de_tabla_hash(struct TablaHash *tabla, const char *clave) {
    // --- 1. Guardián de seguridad: evitamos punteros nulos ---
    if (tabla == NULL || clave == NULL) {
        printf("Error: Tabla o clave nula al intentar eliminar.\n");
        return;
    }

    // --- 2. Calculamos el número de casillero (índice) ---
    int indice = calcular_indice_hash(clave, tabla->capacidad);

    // --- 3. Punteros de seguimiento para recorrer la lista enlazada de colisiones ---
    struct NodoHash *actual = tabla->cubetas[indice];
    struct NodoHash *anterior = NULL;

    // --- 4. Recorremos la cadena buscando la clave exactita ---
    while (actual != NULL) {
        // strcmp devuelve 0 si las cadenas son idénticas
        if (strcmp(actual->clave, clave) == 0) {
            
            // Subcaso A: El nodo que vamos a borrar es el PRIMERO de la lista (la cabeza del casillero)
            if (anterior == NULL) {
                tabla->cubetas[indice] = actual->siguiente;
            } 
            // Subcaso B: El nodo está en medio o al final de la cadena
            else {
                anterior->siguiente = actual->siguiente;
            }

            // Liberamos la memoria del nodo en el Heap
            free(actual);
            return; // ¡Listo, ya borramos y salimos de la función!
        }

        // Avanzamos los dos punteros un paso hacia adelante en la cadena
        anterior = actual;
        actual = actual->siguiente;
    }

    printf("Aviso: Clave '%s' no encontrada para eliminar.\n", clave);
}

// Imprime el contenido de cada cubeta y las listas enlazadas de colisión
void imprimir_tabla_hash(struct TablaHash *tabla) {
    if (tabla == NULL) return;
    
    printf("\n--- DIAGNÓSTICO DE LA TABLA HASH (Capacidad: %d) ---\n", tabla->capacidad);
    for (int i = 0; i < tabla->capacidad; i++) {
        printf("Cubeta [%d]: ", i);
        struct NodoHash *actual = tabla->cubetas[i];
        if (actual == NULL) {
            printf("VACÍA (NULL)\n");
        } else {
            while (actual != NULL) {
                printf("-> [Clave: \"%s\" | Valor: %d] ", actual->clave, actual->valor);
                actual = actual->siguiente;
            }
            printf("-> NULL\n");
        }
    }
    printf("---------------------------------------------------\n\n");
}