
// --- GUARDAS DE INCLUSIÓN ---
// Esto es un candado de seguridad. Evita que el compilador lea este "menú" 
// dos veces por accidente si lo incluimos desde varios archivos.
#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

// --- DEFINICIÓN DE NUESTRA ESTRUCTURA ---
// Aquí creamos el "molde" para los eslabones de nuestra cadena
struct Nodo {
    int dato;               // Aquí guardaremos el número (el contenido)
    struct Nodo *siguiente; // Aquí guardamos la dirección de memoria del próximo eslabón
};

// --- FUNCIONES DE LA LISTA ---
// Solo ponemos la "firma" de la función para que el resto del programa sepa que existe
struct Nodo* crear_nodo(int valor_inicial);
struct Nodo* insertar_al_inicio(struct Nodo *cabeza_actual, int nuevo_valor);
void recorrer_lista(struct Nodo *cabeza);
void liberar_lista(struct Nodo *cabeza);
struct Nodo* insertar_al_final(struct Nodo *cabeza, int nuevo_valor);
struct Nodo* buscar_nodo(struct Nodo *cabeza, int valor_buscado);
struct Nodo* eliminar_nodo(struct Nodo *cabeza, int valor_a_eliminar);
int obtener_longitud(struct Nodo *cabeza);
struct Nodo* invertir_lista(struct Nodo *cabeza);

struct NodoDoble {
    int dato;
    struct NodoDoble *siguiente;
    struct NodoDoble *anterior;
};

struct NodoDoble* crear_nodo_doble(int valor_inicial);
struct NodoDoble* insertar_inicio_doble(struct NodoDoble *cabeza, int nuevo_valor);
void recorrer_lista_doble(struct NodoDoble *cabeza);
void liberar_lista_doble(struct NodoDoble *cabeza);

#endif