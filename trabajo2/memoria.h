/**
 * @file memoria.h
 * @brief Declaraciones para la gestión de memoria en el simulador de sistema operativo.
 *
 * Este archivo define la estructura de datos para representar los bloques de memoria
 * y las funciones que inicializan, asignan y liberan memoria según distintos
 * algoritmos de asignación.
 * 
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#ifndef MEMORIA_H
#define MEMORIA_H

/**
 * @brief Estructura que representa un bloque de memoria en la lista enlazada.
 * 
 * Cada bloque tiene un tamaño, un indicador de disponibilidad (libre u ocupado),
 * y un puntero al siguiente bloque en la lista.
 */
typedef struct BloqueMemoria {
    int tamano;                    /**< Tamaño del bloque de memoria en KB */
    int libre;                     /**< Estado del bloque: 1 si está libre, 0 si está ocupado */
    struct BloqueMemoria *siguiente; /**< Puntero al siguiente bloque de memoria en la lista */
} BloqueMemoria;

/**
 * @brief Inicializa la memoria con una lista de bloques de tamaño especificado.
 * 
 * @param bloques Arreglo de enteros que representa el tamaño de cada bloque de memoria.
 * @param cantidad Número de bloques que se deben crear en la memoria.
 */
void inicializar_memoria(int *bloques, int cantidad);

/**
 * @brief Asigna un bloque de memoria de tamaño adecuado según el algoritmo de asignación especificado.
 * 
 * @param tamano Tamaño de memoria solicitado por el proceso.
 * @param algoritmo Algoritmo de asignación a utilizar (First Fit, Best Fit o Worst Fit).
 * @return int Retorna 1 si la asignación fue exitosa; -1 si no se encontró un bloque adecuado.
 */
int asignar_memoria(int tamano, char *algoritmo);

/**
 * @brief Libera un bloque de memoria previamente asignado, permitiendo que pueda ser reutilizado.
 * 
 * @param direccion Tamaño del bloque de memoria que se desea liberar.
 */
void liberar_memoria(int direccion);

#endif // MEMORIA_H
