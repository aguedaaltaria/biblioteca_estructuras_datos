#include <stdio.h>
#include <stdlib.h>
#include "../encabezados/arboles.h"

// 1. Fábrica para crear un nuevo nodo de árbol binario en el Heap
struct NodoArbolBinario* crear_nodo_arbol(int valor) {
    struct NodoArbolBinario *nuevo_nodo = (struct NodoArbolBinario*)malloc(sizeof(struct NodoArbolBinario));
    
    if (nuevo_nodo == NULL) {
        printf("Error: No hay memoria suficiente para el nodo de árbol.\n");
        return NULL;
    }

    nuevo_nodo->dato = valor;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->altura = 1; // <--- MODIFICADO (Inicializamos altura en 1 para AVL)

    return nuevo_nodo;
}

// 2. Inserción recursiva automática (Árbol Binario de Búsqueda - BST)
struct NodoArbolBinario* insertar_en_arbol(struct NodoArbolBinario *raiz, int valor) {
    if (raiz == NULL) {
        return crear_nodo_arbol(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar_en_arbol(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = insertar_en_arbol(raiz->derecha, valor);
    }

    return raiz;
}

// 3. Recorrido In-order: Izquierda -> Raíz -> Derecha (Ordenado de menor a mayor)
void recorrer_in_order(struct NodoArbolBinario *raiz) {
    if (raiz == NULL) {
        return;
    }
    recorrer_in_order(raiz->izquierda);
    printf("Dato: %d\n", raiz->dato);
    recorrer_in_order(raiz->derecha);
}

// 4. Recorrido Pre-order: Raíz -> Izquierda -> Derecha
void recorrer_pre_order(struct NodoArbolBinario *raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("Dato: %d\n", raiz->dato);
    recorrer_pre_order(raiz->izquierda);
    recorrer_pre_order(raiz->derecha);
}

// 5. Recorrido Post-order: Izquierda -> Derecha -> Raíz
void recorrer_post_order(struct NodoArbolBinario *raiz) {
    if (raiz == NULL) {
        return;
    }
    recorrer_post_order(raiz->izquierda);
    recorrer_post_order(raiz->derecha);
    printf("Dato: %d\n", raiz->dato);
}

// 6. Liberar memoria usando Post-order (Primero hijos, luego el padre)
void liberar_arbol(struct NodoArbolBinario *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberar_arbol(raiz->izquierda);
    liberar_arbol(raiz->derecha);
    free(raiz);
}

// 1. Función auxiliar recursiva: escribe las flechas de parentesco en el archivo abierto
static void escribir_conexiones_dot(struct NodoArbolBinario *raiz, FILE *archivo) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->izquierda != NULL) {
        fprintf(archivo, "    \"%d\" -> \"%d\";\n", raiz->dato, raiz->izquierda->dato);
        escribir_conexiones_dot(raiz->izquierda, archivo);
    }

    if (raiz->derecha != NULL) {
        fprintf(archivo, "    \"%d\" -> \"%d\";\n", raiz->dato, raiz->derecha->dato);
        escribir_conexiones_dot(raiz->derecha, archivo);
    }
}

// 2. Función principal que crea el archivo DOT y renderiza la imagen PNG
void exportar_a_dot(struct NodoArbolBinario *raiz, const char *nombre_archivo_dot, const char *nombre_imagen_png) {
    if (raiz == NULL) {
        printf("El árbol está vacío, no se puede exportar.\n");
        return;
    }

    FILE *archivo = fopen(nombre_archivo_dot, "w");
    if (archivo == NULL) {
        printf("Error: No se pudo crear el archivo en la carpeta dot/\n");
        return;
    }

    fprintf(archivo, "digraph ArbolBST {\n");
    fprintf(archivo, "    node [shape=circle, style=filled, fillcolor=yellow];\n");

    escribir_conexiones_dot(raiz, archivo);

    fprintf(archivo, "}\n");
    fclose(archivo);
    
    printf("¡Archivo DOT generado con éxito en %s!\n", nombre_archivo_dot);

    char comando[512];
    snprintf(comando, sizeof(comando), "dot -Tpng %s -o %s 2>/dev/null", nombre_archivo_dot, nombre_imagen_png);
    
    int resultado = system(comando);
    if (resultado == 0) {
        printf("¡Imagen PNG generada con éxito en %s!\n", nombre_imagen_png);
    } else {
        printf("[Nota] El archivo DOT está listo, pero hubo un detalle al invocar Graphviz.\n");
    }
}

// Búsqueda en BST (O(h))
struct NodoArbolBinario* buscar_en_arbol(struct NodoArbolBinario *raiz, int valor) {
    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }
    if (valor < raiz->dato) {
        return buscar_en_arbol(raiz->izquierda, valor);
    }
    return buscar_en_arbol(raiz->derecha, valor);
}

// Auxiliar para eliminación (sucesor in-order)
static struct NodoArbolBinario* encontrar_minimo(struct NodoArbolBinario *nodo) {
    struct NodoArbolBinario *actual = nodo;
    while (actual != NULL && actual->izquierda != NULL) {
        actual = actual->izquierda;
    }
    return actual;
}

// Eliminación en BST (3 casos: hoja, 1 hijo, 2 hijos)
struct NodoArbolBinario* eliminar_nodo_arbol(struct NodoArbolBinario *raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->dato) {
        raiz->izquierda = eliminar_nodo_arbol(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = eliminar_nodo_arbol(raiz->derecha, valor);
    } else {
        if (raiz->izquierda == NULL) {
            struct NodoArbolBinario *temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            struct NodoArbolBinario *temp = raiz->izquierda;
            free(raiz);
            return temp;
        }

        struct NodoArbolBinario *temp = encontrar_minimo(raiz->derecha);
        raiz->dato = temp->dato;
        raiz->derecha = eliminar_nodo_arbol(raiz->derecha, temp->dato);
    }
    return raiz;
}

int altura_arbol(struct NodoArbolBinario *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int altura_izq = altura_arbol(raiz->izquierda);
    int altura_der = altura_arbol(raiz->derecha);
    int mayor_altura = (altura_izq > altura_der) ? altura_izq : altura_der;
    return 1 + mayor_altura;
}

int contar_nodos(struct NodoArbolBinario *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int nodos_izq = contar_nodos(raiz->izquierda);
    int nodos_der = contar_nodos(raiz->derecha);
    return 1 + nodos_izq + nodos_der;
}

// Obtiene la altura de un nodo de forma segura.
// Si el puntero es NULL (subárbol vacío), su altura por convención es 0.
static int obtener_altura(struct NodoArbolBinario *nodo) {
    if (nodo == NULL) {
        return 0;
    }
    
    return nodo->altura;
}

// Compara dos enteros y retorna el que tenga mayor valor numérico.
static int encontrar_mayor_entero(int primer_valor, int segundo_valor) {
    if (primer_valor > segundo_valor) {
        return primer_valor;
    } else {
        return segundo_valor;
    }
}

// --- FUNCIÓN AUXILIAR (HELPER): Calcular factor de balance ---
static int obtener_balance(struct NodoArbolBinario *nodo) {
    if (nodo == NULL) {
        return 0;
    }
    
    int altura_del_subarbol_izquierdo = obtener_altura(nodo->izquierda);
    int altura_del_subarbol_derecho = obtener_altura(nodo->derecha);
    
    int factor_de_balance = altura_del_subarbol_izquierdo - altura_del_subarbol_derecho;
    
    return factor_de_balance;
}

// --- ROTACIÓN SIMPLE A LA DERECHA (Caso LL) ---
static struct NodoArbolBinario* rotar_derecha(struct NodoArbolBinario *nodo_desbalanceado) {
    struct NodoArbolBinario *nuevo_centro = nodo_desbalanceado->izquierda;
    struct NodoArbolBinario *subarbol_intermedio = nuevo_centro->derecha;

    // 1. Reordenamos los enlaces como un reacomodo de piezas
    nuevo_centro->derecha = nodo_desbalanceado;      // El hijo izquierdo sube de jefe
    nodo_desbalanceado->izquierda = subarbol_intermedio; // La rama del medio pasa al hueco

    // 2. Actualizamos alturas de abajo hacia arriba
    nodo_desbalanceado->altura = 1 + encontrar_mayor_entero(
        obtener_altura(nodo_desbalanceado->izquierda), 
        obtener_altura(nodo_desbalanceado->derecha)
    );
    
    nuevo_centro->altura = 1 + encontrar_mayor_entero(
        obtener_altura(nuevo_centro->izquierda), 
        obtener_altura(nuevo_centro->derecha)
    );

    return nuevo_centro; // Este nodo subió a ser la nueva raíz local
}

// --- ROTACIÓN SIMPLE A LA IZQUIERDA (Caso RR) ---
static struct NodoArbolBinario* rotar_izquierda(struct NodoArbolBinario *nodo_desbalanceado) {
    struct NodoArbolBinario *nuevo_centro = nodo_desbalanceado->derecha;
    struct NodoArbolBinario *subarbol_intermedio = nuevo_centro->izquierda;

    // 1. Reordenamos los enlaces simétricamente
    nuevo_centro->izquierda = nodo_desbalanceado;       // El hijo derecho sube de jefe
    nodo_desbalanceado->derecha = subarbol_intermedio;  // La rama del medio pasa al hueco

    // 2. Actualizamos alturas de abajo hacia arriba
    nodo_desbalanceado->altura = 1 + encontrar_mayor_entero(
        obtener_altura(nodo_desbalanceado->izquierda), 
        obtener_altura(nodo_desbalanceado->derecha)
    );
    
    nuevo_centro->altura = 1 + encontrar_mayor_entero(
        obtener_altura(nuevo_centro->izquierda), 
        obtener_altura(nuevo_centro->derecha)
    );

    return nuevo_centro; // Este nodo subió a ser la nueva raíz local
}

// --- INSERCIÓN AVL CON BALANCE AUTOMÁTICO ---
struct NodoArbolBinario* insertar_avl(struct NodoArbolBinario *raiz, int valor) {
    // 1. Caso base: si llegamos a un espacio vacío, creamos y devolvemos el nuevo nodo
    if (raiz == NULL) {
        return crear_nodo_arbol(valor);
    }

    // 2. Inserción BST normal (recursiva)
    if (valor < raiz->dato) {
        raiz->izquierda = insertar_avl(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = insertar_avl(raiz->derecha, valor);
    } else {
        return raiz; // Ignoramos duplicados
    }

    // 3. Actualizamos la altura de este ancestro de abajo hacia arriba
    int altura_del_subarbol_izquierdo = obtener_altura(raiz->izquierda);
    int altura_del_subarbol_derecho = obtener_altura(raiz->derecha);
    
    raiz->altura = 1 + encontrar_mayor_entero(altura_del_subarbol_izquierdo, altura_del_subarbol_derecho);

    // 4. Calculamos el factor de balance para detectar inclinaciones peligrosas
    int factor_de_balance = obtener_balance(raiz);

    // 5. Evaluamos y corregimos los 4 Casos de Desbalanceo AVL:

    // --- Caso LL (Left-Left): El nuevo valor es menor que el hijo izquierdo ---
    if (factor_de_balance > 1 && valor < raiz->izquierda->dato) {
        return rotar_derecha(raiz);
    }

    // --- Caso RR (Right-Right): El nuevo valor es mayor que el hijo derecho ---
    if (factor_de_balance < -1 && valor > raiz->derecha->dato) {
        return rotar_izquierda(raiz);
    }

    // --- Caso LR (Left-Right): El nuevo valor es mayor que el hijo izquierdo (rotación doble) ---
    if (factor_de_balance > 1 && valor > raiz->izquierda->dato) {
        raiz->izquierda = rotar_izquierda(raiz->izquierda);
        return rotar_derecha(raiz);
    }

    // --- Caso RL (Right-Left): El nuevo valor es menor que el hijo derecho (rotación doble) ---
    if (factor_de_balance < -1 && valor < raiz->derecha->dato) {
        raiz->derecha = rotar_derecha(raiz->derecha);
        return rotar_izquierda(raiz);
    }

    // Si el factor de balance está entre -1, 0 y 1, el nodo está sano
    return raiz;
}