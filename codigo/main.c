/* ==========================================================================
 * HISTORIAL EVOLUTIVO DE LA BIBLIOTECA DE ESTRUCTURAS DE DATOS
 * Este archivo contiene todas las iteraciones de práctica comentadas, 
 * culminando en la prueba final activa al final del archivo.
 * ========================================================================== */

/* --------------------------------------------------------------------------
 * FASE 1: Estructura base y primer "Hola Mundo" (Día 1)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// 
// int main() {
//     printf("¡Hola! Este es el inicio de la biblioteca de estructuras de datos.\n");
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 2: Creación de un nodo estático local en el Stack (Día 1)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Hola! Este es el inicio de la biblioteca de estructuras de datos.\n");
//     struct Nodo mi_primer_nodo;
//     mi_primer_nodo.dato = 42;
//     mi_primer_nodo.siguiente = NULL; 
//     printf("El dato de mi nodo es: %d\n", mi_primer_nodo.dato);
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 3: Introducción a la memoria dinámica (Heap) y factory (Día 2)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Iniciando la fábrica dinámica de nodos!\n");
//     struct Nodo *nodo_dinamico = crear_nodo(500);
//     
//     if (nodo_dinamico != NULL) {
//         printf("Éxito: Se creó un nodo en la memoria dinámica con el dato: %d\n", nodo_dinamico->dato);
//     } else {
//         printf("Error: No se pudo crear el nodo.\n");
//     }
// 
//     free(nodo_dinamico);
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 4: Conexión manual de nodos y primer recorrido con viajero (Día 3)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Construyendo nuestra primera cadena de nodos!\n\n");
//     
//     struct Nodo *nodo1 = crear_nodo(10);
//     struct Nodo *nodo2 = crear_nodo(20);
//     struct Nodo *nodo3 = crear_nodo(30);
// 
//     nodo1->siguiente = nodo2;
//     nodo2->siguiente = nodo3;
// 
//     printf("Recorriendo la lista:\n");
//     struct Nodo *actual = nodo1; 
//     while (actual != NULL) {
//         printf("Visité el nodo con el dato: %d\n", actual->dato);
//         actual = actual->siguiente; 
//     }
// 
//     free(nodo1);
//     free(nodo2);
//     free(nodo3);
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 5: Inserción automatizada al inicio (LIFO) y bucle de limpieza (Día 4)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Construyendo una lista automatizada!\n\n");
//     struct Nodo *mi_lista = NULL;
// 
//     for (int i = 1; i <= 5; i++) {
//         mi_lista = insertar_al_inicio(mi_lista, i * 10); 
//     }
// 
//     printf("Recorriendo la lista:\n");
//     struct Nodo *actual = mi_lista; 
//     while (actual != NULL) {
//         printf("Visité el nodo con el dato: %d\n", actual->dato);
//         actual = actual->siguiente; 
//     }
// 
//     printf("\nIniciando limpieza de memoria...\n");
//     actual = mi_lista; 
//     struct Nodo *siguiente_temporal;
// 
//     while (actual != NULL) {
//         siguiente_temporal = actual->siguiente; 
//         free(actual); 
//         actual = siguiente_temporal; 
//     }
//     printf("¡Memoria liberada con éxito!\n");
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 6: Lista interactiva controlada por usuario mediante scanf (Día 4)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Construyendo una lista interactiva!\n\n");
//     struct Nodo *mi_lista = NULL;
//     int cantidad_nodos;
//     int valor_ingresado;
// 
//     printf("¿Cuántos nodos quieres crear? ");
//     scanf("%d", &cantidad_nodos); 
// 
//     printf("\n¡Perfecto! Vamos a crear %d nodos.\n", cantidad_nodos);
//     for (int i = 1; i <= cantidad_nodos; i++) {
//         printf("Ingresa el número para el nodo %d: ", i);
//         scanf("%d", &valor_ingresado);
//         mi_lista = insertar_al_inicio(mi_lista, valor_ingresado); 
//     }
// 
//     printf("\n--- Resultados de tu lista ---\n");
//     struct Nodo *actual = mi_lista; 
//     while (actual != NULL) {
//         printf("Visité el nodo con el dato: %d\n", actual->dato);
//         actual = actual->siguiente; 
//     }
// 
//     printf("\nIniciando limpieza de memoria...\n");
//     actual = mi_lista; 
//     struct Nodo *siguiente_temporal;
//     while (actual != NULL) {
//         siguiente_temporal = actual->siguiente; 
//         free(actual); 
//         actual = siguiente_temporal; 
//     }
//     printf("¡Memoria liberada con éxito!\n");
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 7: Modularización con Colas (FIFO) y limpieza centralizada (Día 5)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Construyendo una lista interactiva 100%% modular!\n\n");
//     struct Nodo *mi_lista = NULL;
//     int cantidad_nodos;
//     int valor_ingresado;
// 
//     printf("¿Cuántos nodos quieres crear? ");
//     scanf("%d", &cantidad_nodos); 
// 
//     printf("\n¡Perfecto! Vamos a crear %d nodos.\n", cantidad_nodos);
//     for (int i = 1; i <= cantidad_nodos; i++) {
//         printf("Ingresa el número para el nodo %d: ", i);
//         scanf("%d", &valor_ingresado);
//         mi_lista = insertar_al_final(mi_lista, valor_ingresado); 
//     }
// 
//     recorrer_lista(mi_lista);
// 
//     printf("\nIniciando limpieza de memoria...\n");
//     liberar_lista(mi_lista);
//     printf("¡Memoria liberada con éxito!\n");
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 8: Implementación y prueba del Buscador de Nodos (Día 5)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 
// 
// int main() {
//     printf("¡Probando el Buscador de Nodos!\n\n");
//     struct Nodo *mi_lista = NULL;
// 
//     mi_lista = insertar_al_final(mi_lista, 10);
//     mi_lista = insertar_al_final(mi_lista, 20);
//     mi_lista = insertar_al_final(mi_lista, 30);
//     recorrer_lista(mi_lista);
// 
//     int objetivo = 20;
//     struct Nodo *resultado = buscar_nodo(mi_lista, objetivo);
//     if (resultado != NULL) {
//         printf("\n¡Éxito! El número %d fue encontrado en la memoria.\n", objetivo);
//     } else {
//         printf("\nEl número %d no está en la lista.\n", objetivo);
//     }
// 
//     int objetivo_falso = 99;
//     struct Nodo *resultado_falso = buscar_nodo(mi_lista, objetivo_falso);
//     if (resultado_falso != NULL) {
//         printf("¡Éxito! El número %d fue encontrado en la memoria.\n", objetivo_falso);
//     } else {
//         printf("El número %d no está en la lista (como esperábamos).\n", objetivo_falso);
//     }
// 
//     liberar_lista(mi_lista);
//     printf("\nMemoria liberada con éxito.\n");
//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 9 (ACTIVA): Prueba de fuego de cirugía de nodos - Frente, Medio y Final
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Prueba de fuego: Eliminando al frente, al medio y al final!\n\n");
    
//     struct Nodo *mi_lista = NULL;

//     // 1. Creamos una lista de 5 elementos (10, 20, 30, 40, 50)
//     mi_lista = insertar_al_final(mi_lista, 10);
//     mi_lista = insertar_al_final(mi_lista, 20);
//     mi_lista = insertar_al_final(mi_lista, 30);
//     mi_lista = insertar_al_final(mi_lista, 40);
//     mi_lista = insertar_al_final(mi_lista, 50);

//     printf("--- Lista Inicial (5 elementos) ---");
//     recorrer_lista(mi_lista);

//     // 2. Eliminamos uno del FRENTE (el 10) -> Caso especial (cambia la cabeza)
//     printf("\n[Cirugía 1] Eliminando el nodo del frente (10)...\n");
//     mi_lista = eliminar_nodo(mi_lista, 10);
//     recorrer_lista(mi_lista);

//     // 3. Eliminamos uno del MEDIO (el 30) -> Caso general
//     printf("\n[Cirugía 2] Eliminando el nodo del medio (30)...\n");
//     mi_lista = eliminar_nodo(mi_lista, 30);
//     recorrer_lista(mi_lista);

//     // 4. Eliminamos uno del FINAL (el 50) -> Caso general (el último nodo)
//     printf("\n[Cirugía 3] Eliminando el nodo del final (50)...\n");
//     mi_lista = eliminar_nodo(mi_lista, 50);
//     recorrer_lista(mi_lista);

//     // Limpieza final de lo que quedó (20 y 40)
//     liberar_lista(mi_lista);
//     printf("\nMemoria liberada con éxito.\n");

//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 10 (ACTIVA - DÍA 6): Contar elementos de la lista (obtener_longitud)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Iniciando el Día 6: Contando elementos con la nueva función!\n\n");
    
//     struct Nodo *mi_lista = NULL;

//     // 1. Verificamos la longitud de una lista completamente vacía
//     printf("Longitud de la lista vacía: %d nodos.\n", obtener_longitud(mi_lista));

//     // 2. Agregamos tres elementos usando nuestra cola (100, 200, 300)
//     mi_lista = insertar_al_final(mi_lista, 100);
//     mi_lista = insertar_al_final(mi_lista, 200);
//     mi_lista = insertar_al_final(mi_lista, 300);

//     // 3. Recorremos para visualizar
//     recorrer_lista(mi_lista);

//     // 4. Comprobamos la longitud con elementos
//     printf("\nLongitud actual de la lista: %d nodos.\n", obtener_longitud(mi_lista));

//     // Limpieza final de memoria
//     liberar_lista(mi_lista);
//     printf("\nMemoria liberada con éxito.\n");

//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 11 (ACTIVA - DÍA 6): Invertir la lista enlazada (invertir_lista)
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Iniciando el reto de Invertir la Lista!\n\n");
    
//     struct Nodo *mi_lista = NULL;

//     // 1. Creamos una lista ordenada (10, 20, 30)
//     mi_lista = insertar_al_final(mi_lista, 10);
//     mi_lista = insertar_al_final(mi_lista, 20);
//     mi_lista = insertar_al_final(mi_lista, 30);

//     printf("--- Lista Original (Orden de entrada) ---");
//     recorrer_lista(mi_lista);

//     // 2. Invertimos la lista
//     printf("\nInvertiendo los punteros de la lista...\n");
//     mi_lista = invertir_lista(mi_lista);

//     printf("--- Lista Invertida (Nuevo orden) ---");
//     recorrer_lista(mi_lista);

//     // Limpieza final de memoria
//     liberar_lista(mi_lista);
//     printf("\nMemoria liberada con éxito.\n");

//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 12 (ACTIVA - DÍA 6): Introducción a Listas Doblemente Enlazadas
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Iniciando el reto de Listas Doblemente Enlazadas!\n\n");
    
//     struct NodoDoble *mi_lista_doble = NULL;

//     // Insertamos elementos usando inserción al inicio (doble enlace)
//     mi_lista_doble = insertar_inicio_doble(mi_lista_doble, 300);
//     mi_lista_doble = insertar_inicio_doble(mi_lista_doble, 200);
//     mi_lista_doble = insertar_inicio_doble(mi_lista_doble, 100);

//     // Recorremos hacia adelante y hacia atrás para comprobar los enlaces dobles
//     recorrer_lista_doble(mi_lista_doble);

//     // Liberación de memoria de la lista doble
//     liberar_lista_doble(mi_lista_doble);
//     printf("\nMemoria de la lista doble liberada con éxito.\n");

//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 13 (ACTIVA - DÍA 7): Inserción al final en Lista Doblemente Enlazada
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Iniciando el Día 7: Inserción al final en Lista Doble!\n\n");
    
//     struct NodoDoble *mi_lista_doble = NULL;

//     // Insertamos al final (10, 20, 30) - Orden cronológico FIFO
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 10);
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 20);
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 30);

//     // Recorremos hacia adelante y hacia atrás para comprobar los enlaces dobles
//     recorrer_lista_doble(mi_lista_doble);

//     // Liberación de memoria de la lista doble
//     liberar_lista_doble(mi_lista_doble);
//     printf("\nMemoria de la lista doble liberada con éxito.\n");

//     return 0; 
// }


/* --------------------------------------------------------------------------
 * FASE 14 (ACTIVA - DÍA 7): Cirugía múltiple en Lista Doblemente Enlazada
 * -------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Iniciando la Prueba de Cirugía Múltiple en Lista Doble!\n\n");
    
//     struct NodoDoble *mi_lista_doble = NULL;

//     // 1. Insertamos cuatro elementos (10, 20, 30, 40)
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 10);
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 20);
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 30);
//     mi_lista_doble = insertar_al_final_doble(mi_lista_doble, 40);

//     printf("--- Estado Inicial (4 elementos) ---");
//     recorrer_lista_doble(mi_lista_doble);

//     // 2. Cirugía 1: Eliminamos un nodo del FRENTE (el 10) -> Cambia la cabeza
//     printf("\n[Cirugía 1] Eliminando el nodo del frente (10)...\n");
//     mi_lista_doble = eliminar_nodo_doble(mi_lista_doble, 10);
//     recorrer_lista_doble(mi_lista_doble);

//     // 3. Cirugía 2: Eliminamos un nodo del MEDIO (el 30) -> Caso general
//     printf("\n[Cirugía 2] Eliminando el nodo del medio (30)...\n");
//     mi_lista_doble = eliminar_nodo_doble(mi_lista_doble, 30);
//     recorrer_lista_doble(mi_lista_doble);

//     // 4. Liberación de memoria final de lo que quedó (20 y 40)
//     liberar_lista_doble(mi_lista_doble);
//     printf("\nMemoria de la lista doble liberada con éxito.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 15 (ACTIVA - DÍA 8): Árboles Binarios de Búsqueda (BST) y Archivo DOT
 * NOTA DE DISEÑO: Este árbol NO se auto-balancea automáticamente. Dependiendo 
 * del orden de inserción, puede inclinarse o desbalancearse (degenerarse).
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando el Día 8: Árboles Binarios y formato DOT!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos números desordenados (La raíz será 50)
//     raiz = insertar_en_arbol(raiz, 50);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 70);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 40);

//     printf("--- Recorriendo el Árbol In-order (Ordenado de menor a mayor) ---\n");
//     recorrer_in_order(raiz);

//     // Exportamos a DOT y generamos la imagen png en la carpeta imagenes/
//     exportar_a_dot(raiz, "dot/arbol_fase15.dot", "imagenes/arbol_fase15.png");

//     // Liberación de memoria con Post-order interno
//     liberar_arbol(raiz);
//     printf("\nMemoria del árbol liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 16 (ACTIVA - DÍA 8): Demostración de Árbol Desbalanceado (Degenerado)
 * Inserción secuencial (10, 20, 30, 40, 50) para observar la pérdida de forma.
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 16: El Árbol Desbalanceado!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos números en orden ascendente
//     raiz = insertar_en_arbol(raiz, 10);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 40);
//     raiz = insertar_en_arbol(raiz, 50);

//     printf("--- Recorriendo el Árbol Desbalanceado In-order ---\n");
//     recorrer_in_order(raiz);

//     // Exportamos el mapa a DOT y generamos la imagen para ver el desbalance
//     exportar_a_dot(raiz, "dot/arbol_fase16.dot", "imagenes/arbol_fase16.png");

//     // Liberación de memoria segura
//     liberar_arbol(raiz);
//     printf("\nMemoria del árbol desbalanceado liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 17 (ACTIVA - DÍA 8): Comparativa de los 3 Recorridos Clásicos (BST)
 * In-order, Pre-order y Post-order sobre un árbol balanceado.
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include "../encabezados/arboles.h" 

int main() {
    printf("¡Iniciando la Fase 17: Los Tres Recorridos del Árbol!\n\n");
    
    struct NodoArbolBinario *raiz = NULL;

    // Sembramos el árbol simétrico base (Raíz 50)
    raiz = insertar_en_arbol(raiz, 50);
    raiz = insertar_en_arbol(raiz, 30);
    raiz = insertar_en_arbol(raiz, 70);
    raiz = insertar_en_arbol(raiz, 20);
    raiz = insertar_en_arbol(raiz, 40);

    printf("1. --- Recorrido In-order (Izquierda -> Raíz -> Derecha) ---\n");
    recorrer_in_order(raiz); // Debe salir ordenado: 20, 30, 40, 50, 70

    printf("\n2. --- Recorrido Pre-order (Raíz -> Izquierda -> Derecha) ---\n");
    recorrer_pre_order(raiz); // La raíz (50) sale de primera

    printf("\n3. --- Recorrido Post-order (Izquierda -> Derecha -> Raíz) ---\n");
    recorrer_post_order(raiz); // La raíz (50) sale de última

    // Exportamos a DOT para tener el registro visual
    exportar_a_dot(raiz, "dot/arbol_fase17.dot", "imagenes/arbol_fase17.png");

    // Liberación de memoria con Post-order interno
    liberar_arbol(raiz);
    printf("\nMemoria liberada con éxito sin fugas.\n");

    return 0; 
}