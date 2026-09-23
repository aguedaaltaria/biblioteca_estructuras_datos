# Biblioteca de Estructuras de Datos en C 📦

Implementación modular, limpia y didáctica de estructuras de datos fundamentales en **C**, priorizando la gestión explícita de memoria, claridad en la aritmética de índices y cero fugas validadas con Valgrind.

## 🚀 Estructuras Implementadas
- **Listas Enlazadas**: Gestión dinámica de nodos y punteros.
- **Árboles Binarios de Búsqueda (BST)**: Inserción y recorrido jerárquico.
- **Tablas Hash**: Manejo de cubetas y resolución de colisiones por encadenamiento (*chaining*).
- **Min-Heap**: Montículo sobre arreglo plano (`struct Heap`) con aritmética de índices (`2*i+1`, `2*i+2`, `(i-1)/2`), *heapify-up* y *heapify-down*.

## 🛡️ Calidad y Auditoría de Memoria
- **Compilación estricta**: `-Wall -Wextra`
- **Auditoría de RAM**: `valgrind --leak-check=full` (garantizando 0 fugas).

## 🛠️ Cómo compilar y probar
Ejemplo con la fase actual (Min-Heap / Fase 26):
```bash
gcc -Wall -Wextra codigo/main.c codigo/heap.c -o programa_main
./programa_main
valgrind --leak-check=full ./programa_main
