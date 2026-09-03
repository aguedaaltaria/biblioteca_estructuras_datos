
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

#endif