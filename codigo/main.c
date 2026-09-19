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
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 17: Los Tres Recorridos del Árbol!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos el árbol simétrico base (Raíz 50)
//     raiz = insertar_en_arbol(raiz, 50);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 70);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 40);

//     printf("1. --- Recorrido In-order (Izquierda -> Raíz -> Derecha) ---\n");
//     recorrer_in_order(raiz); // Debe salir ordenado: 20, 30, 40, 50, 70

//     printf("\n2. --- Recorrido Pre-order (Raíz -> Izquierda -> Derecha) ---\n");
//     recorrer_pre_order(raiz); // La raíz (50) sale de primera

//     printf("\n3. --- Recorrido Post-order (Izquierda -> Derecha -> Raíz) ---\n");
//     recorrer_post_order(raiz); // La raíz (50) sale de última

//     // Exportamos a DOT para tener el registro visual
//     exportar_a_dot(raiz, "dot/arbol_fase17.dot", "imagenes/arbol_fase17.png");

//     // Liberación de memoria con Post-order interno
//     liberar_arbol(raiz);
//     printf("\nMemoria liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 18 (ACTIVA - DÍA 9): Búsqueda en BST
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 18: Búsqueda en BST!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos árbol base: 50, 30, 70, 20, 40
//     raiz = insertar_en_arbol(raiz, 50);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 70);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 40);

//     exportar_a_dot(raiz, "dot/arbol_fase18.dot", "imagenes/arbol_fase18.png");

//     // Prueba 1: Buscar elemento existente
//     int buscar_val = 40;
//     struct NodoArbolBinario *encontrado = buscar_en_arbol(raiz, buscar_val);
//     if (encontrado != NULL) {
//         printf("✅ Dato %d encontrado en el árbol.\n", encontrado->dato);
//     } else {
//         printf("❌ Dato %d no encontrado.\n", buscar_val);
//     }

//     // Prueba 2: Buscar elemento inexistente
//     int no_existe = 99;
//     struct NodoArbolBinario *no_encontrado = buscar_en_arbol(raiz, no_existe);
//     if (no_encontrado == NULL) {
//         printf("❌ Dato %d correctamente no encontrado (prueba negativa exitosa).\n", no_existe);
//     }

//     // Liberación total
//     liberar_arbol(raiz);
//     printf("\nMemoria liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 19 (ACTIVA - DÍA 9): Eliminación de Nodos en BST
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 19: Eliminación en BST!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos árbol base: 50, 30, 70, 20, 40
//     raiz = insertar_en_arbol(raiz, 50);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 70);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 40);

//     exportar_a_dot(raiz, "dot/arbol_fase19_antes.dot", "imagenes/arbol_fase19_antes.png");

//     printf("--- Recorrido In-order antes de eliminar ---\n");
//     recorrer_in_order(raiz);

//     // Eliminamos el 30 (tiene 2 hijos: 20 y 40)
//     printf("\nEliminando el nodo 30...\n");
//     raiz = eliminar_nodo_arbol(raiz, 30);

//     printf("--- Recorrido In-order post-eliminación ---\n");
//     recorrer_in_order(raiz);

//     exportar_a_dot(raiz, "dot/arbol_fase19_despues.dot", "imagenes/arbol_fase19_despues.png");

//     // Liberación total
//     liberar_arbol(raiz);
//     printf("\nMemoria liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 20 (ACTIVA - DÍA 9): Métricas de Nodos y Altura (Árbol Simétrico)
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 20: Métricas en Árbol Simétrico!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos árbol base simétrico: 50, 30, 70, 20, 40
//     raiz = insertar_en_arbol(raiz, 50);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 70);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 40);

//     exportar_a_dot(raiz, "dot/arbol_fase20.dot", "imagenes/arbol_fase20.png");

//     int total_nodos = contar_nodos(raiz);
//     int altura = altura_arbol(raiz);

//     printf("📊 Total de nodos en el árbol: %d\n", total_nodos);
//     printf("📏 Altura máxima del árbol: %d\n", altura);

//     liberar_arbol(raiz);
//     printf("\nMemoria liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 21 (ACTIVA - DÍA 9): Métricas en Árbol Degenerado (Desbalanceado)
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 21: Métricas en Árbol Degenerado!\n\n");
    
//     struct NodoArbolBinario *raiz = NULL;

//     // Sembramos secuencia ascendente (degeneración a lista)
//     raiz = insertar_en_arbol(raiz, 10);
//     raiz = insertar_en_arbol(raiz, 20);
//     raiz = insertar_en_arbol(raiz, 30);
//     raiz = insertar_en_arbol(raiz, 40);
//     raiz = insertar_en_arbol(raiz, 50);

//     exportar_a_dot(raiz, "dot/arbol_fase21.dot", "imagenes/arbol_fase21.png");

//     int total_nodos = contar_nodos(raiz);
//     int altura = altura_arbol(raiz);

//     printf("📊 Total de nodos: %d\n", total_nodos);
//     printf("⚠️ Altura degradada (debería ser menor si estuviera balanceado): %d\n", altura);

//     liberar_arbol(raiz);
//     printf("\nMemoria liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 22 (ACTIVA - DÍA 9): Contraste BST (Sin balancear) vs AVL (Balanceado)
 * Entrada: Secuencia estricta 10, 20, 30, 40, 50
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/arboles.h" 

// int main() {
//     printf("¡Iniciando la Fase 22: Contraste Visual BST vs AVL!\n\n");
    
//     int secuencia[] = {10, 20, 30, 40, 50};
//     int total_elementos = 5;

//     // --- 1. EL "ANTES": Árbol sin balancear (BST clásico) ---
//     printf("--- [ANTES] Insertando con BST tradicional ---\n");
//     struct NodoArbolBinario *raiz_sin_balancear = NULL;
//     for (int i = 0; i < total_elementos; i++) {
//         raiz_sin_balancear = insertar_en_arbol(raiz_sin_balancear, secuencia[i]);
//     }
//     exportar_a_dot(raiz_sin_balancear, "dot/arbol_fase22_sin_balancear.dot", "imagenes/arbol_fase22_sin_balancear.png");
//     printf("📐 Altura BST sin balancear: %d (columna / lista enlazada)\n", altura_arbol(raiz_sin_balancear));
//     liberar_arbol(raiz_sin_balancear);

//     printf("\n--------------------------------------------------\n\n");

//     // --- 2. EL "DESPUÉS": Árbol auto-balanceado (AVL) ---
//     printf("--- [DESPUÉS] Insertando con AVL (auto-balanceo con rotaciones) ---\n");
//     struct NodoArbolBinario *raiz_balanceada = NULL;
//     for (int i = 0; i < total_elementos; i++) {
//         raiz_balanceada = insertar_avl(raiz_balanceada, secuencia[i]);
//     }
//     exportar_a_dot(raiz_balanceada, "dot/arbol_fase22_balanceado.dot", "imagenes/arbol_fase22_balanceado.png");
//     printf("✨ Altura AVL balanceada: %d (estructura óptima ramificada)\n", altura_arbol(raiz_balanceada));
//     liberar_arbol(raiz_balanceada);

//     printf("\nMemoria de ambos escenarios liberada con éxito sin fugas.\n");

//     return 0; 
// }


/* ==========================================================================
 * FASE 23 (DÍA 10): Creación de Tabla Hash e Inserción básica/colisiones
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "../encabezados/tabla_hash.h"

// int main() {
//     printf("¡Iniciando Fase 23: Creación e Inserción en Tabla Hash!\n\n");

//     int capacidad_pequena = 5; // Capacidad reducida a propósito para evidenciar encadenamiento
//     struct TablaHash *tabla = crear_tabla_hash(capacidad_pequena);
    
//     if (tabla == NULL) {
//         printf("Error crítico: no se pudo crear la tabla hash.\n");
//         return 1;
//     }

//     // Insertamos pares clave-valor
//     insertar_en_tabla_hash(tabla, "gilda", 42);
//     insertar_en_tabla_hash(tabla, "carlos", 88);
//     insertar_en_tabla_hash(tabla, "beatriz", 100);

//     printf("Inserciones completadas en tabla con capacidad %d.\n", capacidad_pequena);
//     imprimir_tabla_hash(tabla);

//     // Limpiamos memoria
//     liberar_tabla_hash(tabla);
//     printf("Memoria de la tabla liberada sin fugas.\n");

//     return 0;
// }


/* ==========================================================================
 * FASE 24 (DÍA 10): Pruebas de Búsqueda en Tabla Hash (con colisiones)
 * ========================================================================== */
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "../encabezados/tabla_hash.h"

// int main() {
//     printf("¡Iniciando Fase 24: Pruebas de Búsqueda en Tabla Hash!\n\n");

//     int capacidad = 5;
//     struct TablaHash *tabla = crear_tabla_hash(capacidad);
//     if (tabla == NULL) {
//         printf("Error crítico: no se pudo crear la tabla hash.\n");
//         return 1;
//     }

//     // Insertamos datos (creando colisiones en cubeta 3)
//     insertar_en_tabla_hash(tabla, "gilda", 42);     // Cubeta 3 (fondo)
//     insertar_en_tabla_hash(tabla, "beatriz", 100);  // Cubeta 3 (cabeza / colisión)
//     insertar_en_tabla_hash(tabla, "carlos", 88);    // Cubeta 4

//     imprimir_tabla_hash(tabla);

//     bool encontrado = false;
//     int valor_encontrado = 0;

//     // --- Caso 1: Buscar elemento al frente de la cadena colisionada ("beatriz") ---
//     valor_encontrado = buscar_en_tabla_hash(tabla, "beatriz", &encontrado);
//     if (encontrado) {
//         printf("🔍 [TEST 1] Clave 'beatriz' encontrada -> Valor: %d (¡Correcto!)\n", valor_encontrado);
//     } else {
//         printf("❌ [TEST 1] Error: 'beatriz' debió encontrarse.\n");
//     }

//     // --- Caso 2: Buscar elemento al fondo de la cadena colisionada ("gilda") ---
//     valor_encontrado = buscar_en_tabla_hash(tabla, "gilda", &encontrado);
//     if (encontrado) {
//         printf("🔍 [TEST 2] Clave 'gilda' encontrada -> Valor: %d (¡Correcto! Recorrió la cadena)\n", valor_encontrado);
//     } else {
//         printf("❌ [TEST 2] Error: 'gilda' debió encontrarse.\n");
//     }

//     // --- Caso 3: Buscar clave ausente ("felipe") ---
//     valor_encontrado = buscar_en_tabla_hash(tabla, "felipe", &encontrado);
//     if (!encontrado) {
//         printf("🔍 [TEST 3] Clave 'felipe' no existe en la tabla (¡Correcto!)\n");
//     } else {
//         printf("❌ [TEST 3] Error: 'felipe' no debería existir.\n");
//     }

//     // Limpiamos memoria
//     liberar_tabla_hash(tabla);
//     printf("\nMemoria liberada sin fugas tras pruebas de búsqueda.\n");

//     return 0;
// }


/* ==========================================================================
 * FASE 25 (DÍA 10): Pruebas de Eliminación en Tabla Hash (con colisiones)
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../encabezados/tabla_hash.h"

int main() {
    printf("¡Iniciando Fase 25: Pruebas de Eliminación en Tabla Hash!\n\n");

    int capacidad = 5;
    struct TablaHash *tabla = crear_tabla_hash(capacidad);
    if (tabla == NULL) {
        printf("Error crítico: no se pudo crear la tabla hash.\n");
        return 1;
    }

    // Insertamos datos (creando colisiones en cubeta 3)
    insertar_en_tabla_hash(tabla, "gilda", 42);     // Cubeta 3 (fondo)
    insertar_en_tabla_hash(tabla, "beatriz", 100);  // Cubeta 3 (cabeza / colisión)
    insertar_en_tabla_hash(tabla, "carlos", 88);    // Cubeta 4

    printf("--- ESTADO INICIAL ---\n");
    imprimir_tabla_hash(tabla);

    // --- Caso 1: Eliminar nodo interno/fondo de la cadena ('gilda') ---
    printf("🗑️ [TEST 1] Eliminando 'gilda' (fondo de la cadena en cubeta 3)...\n");
    eliminar_de_tabla_hash(tabla, "gilda");
    imprimir_tabla_hash(tabla);

    // --- Caso 2: Eliminar la cabeza de la cadena ('beatriz') ---
    printf("🗑️ [TEST 2] Eliminando 'beatriz' (cabeza de la cadena en cubeta 3)...\n");
    eliminar_de_tabla_hash(tabla, "beatriz");
    imprimir_tabla_hash(tabla);

    // --- Caso 3: Intentar eliminar clave ausente ('felipe') ---
    printf("🗑️ [TEST 3] Intentando eliminar clave ausente 'felipe'...\n");
    eliminar_de_tabla_hash(tabla, "felipe");

    // Limpiamos memoria
    liberar_tabla_hash(tabla);
    printf("\nMemoria liberada sin fugas tras pruebas de eliminación.\n");

    return 0;
}