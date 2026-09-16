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

    return nuevo_nodo;
}

// 2. Inserción recursiva automática (Árbol Binario de Búsqueda - BST)
struct NodoArbolBinario* insertar_en_arbol(struct NodoArbolBinario *raiz, int valor) {
    // Caso base: Si llegamos a un espacio vacío, aquí construimos la casa nueva
    if (raiz == NULL) {
        return crear_nodo_arbol(valor);
    }

    // Decisión inteligente basada en el valor:
    if (valor < raiz->dato) {
        // Si es menor, nos vamos por la izquierda (recursividad)
        raiz->izquierda = insertar_en_arbol(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        // Si es mayor, nos vamos por la derecha (recursividad)
        raiz->derecha = insertar_en_arbol(raiz->derecha, valor);
    }
    // Si el valor es idéntico, no hacemos nada (evitamos duplicados)

    // Devolvemos la raíz actual intacta para mantener los enlaces
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

    // Si tiene hijo izquierdo, escribimos la conexión: "padre" -> "izquierdo";
    if (raiz->izquierda != NULL) {
        fprintf(archivo, "    \"%d\" -> \"%d\";\n", raiz->dato, raiz->izquierda->dato);
        // Llamada recursiva para seguir bajando por la izquierda
        escribir_conexiones_dot(raiz->izquierda, archivo);
    }

    // Si tiene hijo derecho, escribimos la conexión: "padre" -> "derecho";
    if (raiz->derecha != NULL) {
        fprintf(archivo, "    \"%d\" -> \"%d\";\n", raiz->dato, raiz->derecha->dato);
        // Llamada recursiva para seguir bajando por la derecha
        escribir_conexiones_dot(raiz->derecha, archivo);
    }
}

// 2. Función principal que crea el archivo DOT y renderiza la imagen PNG
void exportar_a_dot(struct NodoArbolBinario *raiz, const char *nombre_archivo_dot, const char *nombre_imagen_png) {
    if (raiz == NULL) {
        printf("El árbol está vacío, no se puede exportar.\n");
        return;
    }

    // Abrimos el archivo en modo escritura ("w") dentro de la carpeta dot/
    FILE *archivo = fopen(nombre_archivo_dot, "w");
    if (archivo == NULL) {
        printf("Error: No se pudo crear el archivo en la carpeta dot/\n");
        return;
    }

    // Escribimos la cabecera con el color amarillo
    fprintf(archivo, "digraph ArbolBST {\n");
    fprintf(archivo, "    node [shape=circle, style=filled, fillcolor=yellow];\n");

    // Invocamos la función recursiva para pintar las uniones
    escribir_conexiones_dot(raiz, archivo);

    // Cerramos la llave y el archivo
    fprintf(archivo, "}\n");
    fclose(archivo);
    
    printf("¡Archivo DOT generado con éxito en %s!\n", nombre_archivo_dot);

    // --- LA MAGIA DE GRAPHVIZ ---
    // Construimos el comando de la terminal de manera segura con snprintf
    char comando[512];
    snprintf(comando, sizeof(comando), "dot -Tpng %s -o %s 2>/dev/null", nombre_archivo_dot, nombre_imagen_png);
    
    // Ejecutamos el comando en el sistema operativo con system()
    int resultado = system(comando);
    if (resultado == 0) {
        printf("¡Imagen PNG generada con éxito en %s!\n", nombre_imagen_png);
    } else {
        printf("[Nota] El archivo DOT está listo, pero hubo un detalle al invocar Graphviz.\n");
    }
}