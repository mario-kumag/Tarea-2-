/**
 * @file planificador.h
 * @brief Declaraciones para la planificación de procesos en el simulador de sistema operativo.
 *
 * Este archivo define la estructura de datos para representar un proceso
 * y declara las funciones necesarias para inicializar y gestionar la cola de
 * procesos, además de la función de planificación.
 * 
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

/**
 * @brief Estructura que representa un proceso en el simulador.
 * 
 * Cada proceso tiene un nombre, un tiempo de ejecución, la memoria solicitada
 * y un puntero al siguiente proceso en la cola. Esta estructura se utiliza para
 * formar la lista enlazada de procesos en espera.
 */
typedef struct Proceso {
    char nombre[10];                  /**< Nombre del proceso */
    int tiempo_ejecucion;             /**< Tiempo de ejecución del proceso en unidades de tiempo */
    int memoria_solicitada;           /**< Cantidad de memoria solicitada por el proceso en KB */
    struct Proceso *siguiente;        /**< Puntero al siguiente proceso en la cola */
} Proceso;

/**
 * @brief Inicializa la cola de procesos dejándola vacía.
 * 
 * Establece el puntero de la cola de procesos en NULL, indicando que no hay
 * procesos en espera en la cola.
 */
void inicializar_cola();

/**
 * @brief Agrega un nuevo proceso a la cola de procesos.
 * 
 * Inserta el proceso al inicio de la lista enlazada, representando la cola de
 * espera de procesos en el simulador.
 * 
 * @param proceso Puntero al proceso que se desea añadir a la cola.
 */
void agregar_proceso(Proceso *proceso);

/**
 * @brief Planifica la ejecución de procesos en la cola según el algoritmo especificado.
 * 
 * La función aplica uno de los algoritmos de planificación (FIFO, Round Robin, SJF)
 * para organizar la ejecución de los procesos en la cola de espera.
 * 
 * @param algoritmo Cadena de caracteres que indica el algoritmo de planificación a utilizar.
 */
void planificar(char *algoritmo);

#endif // PLANIFICADOR_H
