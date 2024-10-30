/**
 * @file proceso.c
 * @brief Módulo de creación y destrucción de procesos para el simulador de sistema operativo.
 *
 * Este archivo contiene las funciones necesarias para crear un proceso con
 * sus parámetros de ejecución y memoria solicitada, y para liberar la memoria
 * ocupada por un proceso cuando este finaliza.
 * 
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#include <stdlib.h>
#include <string.h>
#include "proceso.h"

/**
 * @brief Crea un proceso con los parámetros especificados.
 * 
 * Esta función reserva memoria para un nuevo proceso, asigna su nombre, tiempo
 * de ejecución y cantidad de memoria solicitada. Al finalizar, retorna un puntero
 * al proceso creado.
 * 
 * @param nombre Nombre del proceso.
 * @param tiempo_ejecucion Tiempo de ejecución requerido por el proceso.
 * @param memoria_solicitada Cantidad de memoria solicitada por el proceso en KB.
 * @return Proceso* Puntero al proceso recién creado.
 */
Proceso* crear_proceso(char* nombre, int tiempo_ejecucion, int memoria_solicitada) {
    Proceso *proceso = (Proceso*)malloc(sizeof(Proceso));
    strcpy(proceso->nombre, nombre);
    proceso->tiempo_ejecucion = tiempo_ejecucion;
    proceso->memoria_solicitada = memoria_solicitada;
    proceso->siguiente = NULL;
    return proceso;
}

/**
 * @brief Libera la memoria ocupada por un proceso.
 * 
 * Esta función libera la memoria asignada a un proceso, destruyendo
 * el proceso especificado para evitar fugas de memoria.
 * 
 * @param proceso Puntero al proceso que se desea destruir.
 */
void destruir_proceso(Proceso *proceso) {
    free(proceso);
}
