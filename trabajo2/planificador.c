/**
 * @file planificador.c
 * @brief Módulo de planificación de procesos para el simulador de sistema operativo.
 *
 * Este archivo contiene las funciones para inicializar y gestionar la cola de
 * procesos, así como la función de planificación que aplica diferentes algoritmos,
 * como FIFO, Round Robin y SJF (Shortest Job First).
 * 
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "planificador.h"
#include "memoria.h"

/**
 * @brief Puntero a la cola de procesos en el simulador.
 * 
 * La cola de procesos es una lista enlazada donde se almacenan los procesos que
 * están en espera de ejecución. Cada nodo representa un proceso en la simulación.
 */
Proceso *cola_procesos = NULL;

/**
 * @brief Inicializa la cola de procesos como vacía.
 * 
 * Esta función establece el puntero de la cola de procesos en NULL, indicando
 * que no hay procesos en la cola.
 */
void inicializar_cola() {
    cola_procesos = NULL;
}

/**
 * @brief Agrega un proceso a la cola de procesos.
 * 
 * Esta función toma un proceso y lo añade al inicio de la lista enlazada de
 * procesos, representando la cola de espera de procesos por ejecutar.
 * 
 * @param proceso Puntero al proceso que se desea añadir a la cola.
 */
void agregar_proceso(Proceso *proceso) {
    proceso->siguiente = cola_procesos;
    cola_procesos = proceso;
}

/**
 * @brief Planifica la ejecución de procesos según el algoritmo especificado.
 * 
 * Esta función aplica el algoritmo de planificación proporcionado para organizar
 * la ejecución de los procesos en la cola. Los algoritmos disponibles incluyen:
 * - FIFO (First In, First Out)
 * - Round Robin
 * - SJF (Shortest Job First)
 * 
 * @param algoritmo Cadena de caracteres que indica el algoritmo de planificación a utilizar.
 */
void planificar(char *algoritmo) {
    if (strcmp(algoritmo, "FIFO") == 0) {
        // Implementación FIFO
    } else if (strcmp(algoritmo, "Round Robin") == 0) {
        // Implementación Round Robin
    } else if (strcmp(algoritmo, "SJF") == 0) {
        // Implementación SJF
    }
}
