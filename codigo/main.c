// #include <stdio.h>

// // Mucho de este archivo sera hecho con la funcion de recordar y aprender

// // La función principal donde arranca nuestro programa
// int main() {
//     printf("¡Hola! Este es el inicio de la biblioteca de estructuras de datos.\n");
    
//     // Retornar 0 significa que el programa terminó sin errores
//     return 0; 
// }


// #include <stdio.h>
// // Incluimos nuestro propio archivo usando comillas dobles en lugar de <>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Hola! Este es el inicio de la biblioteca de estructuras de datos.\n");
    
//     // Vamos a crear nuestro primer nodo directamente en la memoria local (Stack)
//     struct Nodo mi_primer_nodo;
    
//     // Le asignamos un valor
//     mi_primer_nodo.dato = 42;
//     // Como es el único nodo, no hay siguiente, así que apunta a la "nada" (NULL)
//     mi_primer_nodo.siguiente = NULL; 

//     // Imprimimos el valor para ver si funcionó
//     printf("El dato de mi nodo es: %d\n", mi_primer_nodo.dato);
    
//     return 0; 
// }


// #include <stdio.h>
// #include <stdlib.h> // Necesitamos esto aquí también por si acaso (buenas prácticas)
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Iniciando la fábrica dinámica de nodos!\n");
    
//     // En lugar de "struct Nodo mi_nodo;", ahora declaramos un PUNTERO (*).
//     // Y en vez de asignarle valores a mano, llamamos a la función que creamos.
//     // Le pasamos el número 500 como dato inicial.
//     struct Nodo *nodo_dinamico = crear_nodo(500);
    
//     // Verificamos que la fábrica no nos haya devuelto NULL (un error)
//     if (nodo_dinamico != NULL) {
//         // Como 'nodo_dinamico' es un puntero (una dirección), ¡usamos la flecha!
//         printf("Éxito: Se creó un nodo en la memoria dinámica con el dato: %d\n", nodo_dinamico->dato);
//     } else {
//         printf("Error: No se pudo crear el nodo.\n");
//     }

//     free(nodo_dinamico);

//     return 0; 
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Construyendo nuestra primera cadena de nodos!\n\n");
    
//     // 1. Pedimos tres nodos a nuestra fábrica
//     struct Nodo *nodo1 = crear_nodo(10);
//     struct Nodo *nodo2 = crear_nodo(20);
//     struct Nodo *nodo3 = crear_nodo(30);

//     // 2. Construimos las carreteras (las conexiones)
//     // El "siguiente" del nodo1 apuntará a la dirección del nodo2
//     nodo1->siguiente = nodo2;
//     // El "siguiente" del nodo2 apuntará a la dirección del nodo3
//     nodo2->siguiente = nodo3;
//     // El nodo3 ya apunta a NULL (la nada) porque así lo configuró la fábrica

//     // 3. ¡EL VIAJE! Vamos a recorrer la lista
//     printf("Recorriendo la lista:\n");
    
//     // Creamos un puntero "viajero" que empieza en la primera casa
//     struct Nodo *actual = nodo1; 

//     // Mientras el viajero no llegue a un callejón sin salida (NULL)...
//     while (actual != NULL) {
//         printf("Visité el nodo con el dato: %d\n", actual->dato);
        
//         // El viajero toma el taxi hacia la siguiente dirección
//         actual = actual->siguiente; 
//     }

//     // 4. Limpieza sagrada (liberamos la memoria de cada casa)
//     free(nodo1);
//     free(nodo2);
//     free(nodo3);

//     return 0; 
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include "../encabezados/lista_enlazada.h" 

// int main() {
//     printf("¡Construyendo una lista automatizada!\n\n");
    
//     // 1. Empezamos con una lista vacía (la cabeza apunta a la nada)
//     struct Nodo *mi_lista = NULL;

//     // 2. Usamos un bucle para insertar 5 nodos automáticamente
//     // Como insertamos "al inicio", el último en entrar será el primero en la lista.
//     for (int i = 1; i <= 5; i++) {
//         // Multiplicamos por 10 solo para que los datos sean 10, 20, 30, 40, 50
//         mi_lista = insertar_al_inicio(mi_lista, i * 10); 
//     }

//     // 3. ¡EL VIAJE! Recorremos la lista igual que antes
//     printf("Recorriendo la lista:\n");
//     struct Nodo *actual = mi_lista; 
//     while (actual != NULL) {
//         printf("Visité el nodo con el dato: %d\n", actual->dato);
//         actual = actual->siguiente; 
//     }

//     // 4. Limpieza masiva (El equipo de demolición)
//     printf("\nIniciando limpieza de memoria...\n");
//     actual = mi_lista; // Volvemos a poner al viajero al inicio
//     struct Nodo *siguiente_temporal;

//     while (actual != NULL) {
//         // GUARDAMOS la dirección de la siguiente casa antes de demoler la actual
//         siguiente_temporal = actual->siguiente; 
        
//         // DEMOLEMOS la casa actual
//         free(actual); 
        
//         // EL VIAJERO se mueve a la dirección que guardamos
//         actual = siguiente_temporal; 
//     }
//     printf("¡Memoria liberada con éxito!\n");

//     return 0; 
// }


#include <stdio.h>
#include <stdlib.h>
#include "../encabezados/lista_enlazada.h" 

int main() {
    printf("¡Construyendo una lista interactiva!\n\n");
    
    struct Nodo *mi_lista = NULL;
    int cantidad_nodos; // Aquí guardaremos el tamaño que elijas
    int valor_ingresado; // Aquí guardaremos cada número que escribas

    // 1. Preguntamos el tamaño de la lista
    printf("¿Cuántos nodos quieres crear? ");
    // Le pasamos a scanf la dirección de memoria (&) de cantidad_nodos
    scanf("%d", &cantidad_nodos); 

    printf("\n¡Perfecto! Vamos a crear %d nodos.\n", cantidad_nodos);

    // 2. Bucle interactivo para pedir los valores uno por uno
    for (int i = 1; i <= cantidad_nodos; i++) {
        printf("Ingresa el número para el nodo %d: ", i);
        scanf("%d", &valor_ingresado);
        
        // Insertamos el valor que acabas de escribir en la lista
        mi_lista = insertar_al_inicio(mi_lista, valor_ingresado); 
    }

    // 3. ¡EL VIAJE! Recorremos la lista
    printf("\n--- Resultados de tu lista ---\n");
    struct Nodo *actual = mi_lista; 
    while (actual != NULL) {
        printf("Visité el nodo con el dato: %d\n", actual->dato);
        actual = actual->siguiente; 
    }

    // 4. Limpieza masiva
    printf("\nIniciando limpieza de memoria...\n");
    actual = mi_lista; 
    struct Nodo *siguiente_temporal;

    while (actual != NULL) {
        siguiente_temporal = actual->siguiente; 
        free(actual); 
        actual = siguiente_temporal; 
    }
    printf("¡Memoria liberada con éxito!\n");

    return 0; 
}