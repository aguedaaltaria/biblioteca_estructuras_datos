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


#include <stdio.h>
#include <stdlib.h> // Necesitamos esto aquí también por si acaso (buenas prácticas)
#include "../encabezados/lista_enlazada.h" 

int main() {
    printf("¡Iniciando la fábrica dinámica de nodos!\n");
    
    // En lugar de "struct Nodo mi_nodo;", ahora declaramos un PUNTERO (*).
    // Y en vez de asignarle valores a mano, llamamos a la función que creamos.
    // Le pasamos el número 500 como dato inicial.
    struct Nodo *nodo_dinamico = crear_nodo(500);
    
    // Verificamos que la fábrica no nos haya devuelto NULL (un error)
    if (nodo_dinamico != NULL) {
        // Como 'nodo_dinamico' es un puntero (una dirección), ¡usamos la flecha!
        printf("Éxito: Se creó un nodo en la memoria dinámica con el dato: %d\n", nodo_dinamico->dato);
    } else {
        printf("Error: No se pudo crear el nodo.\n");
    }

    free(nodo_dinamico);

    return 0; 
}