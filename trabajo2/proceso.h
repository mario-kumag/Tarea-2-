/**
 * @file proceso.h
 * @brief Declaraciones de funciones para la creación y destrucción de procesos.
 *
 * Este archivo define las funciones necesarias para crear un proceso,
 * asignando sus parámetros de ejecución y memoria solicitada, así como para
 * liberar la memoria utilizada por el proceso cuando este termina.
 * 
 * Incluye también la estructura `Proceso` desde "planificador.h" para
 * su uso en el simulador.
 * 
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#ifndef PROCESO_H
#define PROCESO_H

#include "planificador.h"

/**
 * @brief Crea un proceso y asigna sus parámetros.
 * 
 * Esta función reserva memoria para un proceso nuevo, le asigna el nombre,
 * tiempo de ejecución y cantidad de memoria solicitada, y retorna un puntero
 * al proceso creado.
 * 
 * @param nombre Nombre del proceso.
 * @param tiempo_ejecucion Tiempo de ejecución requerido por el proceso.
 * @param memoria_solicitada Cantidad de memoria solicitada por el proceso en KB.
 * @return Proceso* Puntero al proceso recién creado.
 */
Proceso* crear_proceso(char* nombre, int tiempo_ejecucion, int memoria_solicitada);

/**
 * @brief Libera la memoria ocupada por un proceso.
 * 
 * Esta función libera la memoria asignada a un proceso, destruyendo
 * el proceso especificado para evitar fugas de memoria.
 * 
 * @param proceso Puntero al proceso que se desea destruir.
 */
void destruir_proceso(Proceso *proceso);

#endif // PROCESO_H
