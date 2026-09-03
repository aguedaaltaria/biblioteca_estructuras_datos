// #include <stdio.h>

// // Mucho de este archivo sera hecho con la funcion de recordar y aprender

// // La función principal donde arranca nuestro programa
// int main() {
//     printf("¡Hola! Este es el inicio de la biblioteca de estructuras de datos.\n");
    
//     // Retornar 0 significa que el programa terminó sin errores
//     return 0; 
// }


#include <stdio.h>
// Incluimos nuestro propio archivo usando comillas dobles en lugar de <>
#include "../encabezados/lista_enlazada.h" 

int main() {
    printf("¡Hola! Este es el inicio de la biblioteca de estructuras de datos.\n");
    
    // Vamos a crear nuestro primer nodo directamente en la memoria local (Stack)
    struct Nodo mi_primer_nodo;
    
    // Le asignamos un valor
    mi_primer_nodo.dato = 42;
    // Como es el único nodo, no hay siguiente, así que apunta a la "nada" (NULL)
    mi_primer_nodo.siguiente = NULL; 

    // Imprimimos el valor para ver si funcionó
    printf("El dato de mi nodo es: %d\n", mi_primer_nodo.dato);
    
    return 0; 
}