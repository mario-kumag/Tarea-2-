/**
 * @file memoria.c
 * @brief Módulo de gestión de memoria para el simulador de sistema operativo.
 *
 * Este archivo contiene funciones para inicializar, asignar y liberar bloques de
 * memoria en el simulador. Los algoritmos de asignación permiten simular diferentes
 * métodos de gestión de memoria, como First Fit, Best Fit y Worst Fit.
 *
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"

/**
 * @brief Puntero inicial a la lista enlazada de bloques de memoria.
 * 
 * La lista enlazada permite representar la memoria como una serie de bloques,
 * donde cada bloque tiene un tamaño y un estado (libre u ocupado).
 */
BloqueMemoria *memoria = NULL;

/**
 * @brief Inicializa la memoria con una lista de bloques de tamaño especificado.
 * 
 * Esta función toma un arreglo de tamaños de bloques y crea una lista enlazada
 * de bloques de memoria, donde cada bloque se marca inicialmente como libre.
 * 
 * @param bloques Arreglo de enteros que representa el tamaño de cada bloque.
 * @param cantidad Número de bloques a inicializar en la memoria.
 */
void inicializar_memoria(int *bloques, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        BloqueMemoria *nuevo = (BloqueMemoria*)malloc(sizeof(BloqueMemoria));
        nuevo->tamano = bloques[i];
        nuevo->libre = 1;               // Marca el bloque como libre
        nuevo->siguiente = memoria;     // Inserta al inicio de la lista
        memoria = nuevo;
    }
}

/**
 * @brief Asigna un bloque de memoria de tamaño adecuado según el algoritmo especificado.
 * 
 * Esta función recorre la lista de bloques y encuentra un bloque libre que sea lo
 * suficientemente grande para cumplir con el tamaño solicitado. Cambia el estado
 * del bloque a ocupado si encuentra uno adecuado.
 * 
 * @param tamano Tamaño de memoria requerido por el proceso.
 * @param algoritmo Algoritmo de asignación a utilizar (First Fit, Best Fit o Worst Fit).
 * @return int Retorna 1 si la asignación fue exitosa, -1 si no se encontró un bloque adecuado.
 */
int asignar_memoria(int tamano, char *algoritmo) {
    BloqueMemoria *bloque = memoria;
    // Lógica para First Fit, Best Fit y Worst Fit
    while (bloque != NULL) {
        if (bloque->libre && bloque->tamano >= tamano) {
            bloque->libre = 0;          // Marca el bloque como ocupado
            return 1;                   // Retorna éxito en la asignación
        }
        bloque = bloque->siguiente;
    }
    return -1;                          // No se encontró un bloque adecuado
}

/**
 * @brief Libera un bloque de memoria previamente asignado.
 * 
 * La función recorre la lista de bloques y, cuando encuentra el bloque con el
 * tamaño especificado, cambia su estado a libre para que pueda ser reutilizado.
 * 
 * @param direccion Tamaño del bloque de memoria que se desea liberar.
 */
void liberar_memoria(int direccion) {
    BloqueMemoria *bloque = memoria;
    while (bloque != NULL) {
        if (bloque->tamano == direccion) {
            bloque->libre = 1;          // Marca el bloque como libre
            return;
        }
        bloque = bloque->siguiente;
    }
}
