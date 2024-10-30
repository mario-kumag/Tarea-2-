/**
 * @file main.c
 * @brief Simulador de un sistema operativo que gestiona memoria y procesos.
 *
 * Este archivo contiene las funciones principales para iniciar la simulación,
 * leer el archivo de entrada y gestionar la ejecución de procesos en base
 * a los parámetros de memoria y planificación.
 *
 * @authors 
 * Mario Calbuyahue 
 * Constanza Araya 
 * Felipe Paillacar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoria.h"
#include "planificador.h"
#include "proceso.h"
#include "time.h"

/**
 * @brief Lee el archivo de entrada y configura los parámetros de la simulación.
 * 
 * La función toma el nombre del archivo de entrada, lo abre y extrae los parámetros
 * de configuración de memoria y planificación, así como los datos de cada proceso.
 * Luego, simula un retardo aleatorio para cada proceso antes de imprimir su información.
 * 
 * @param filename Nombre del archivo de entrada que contiene los datos de simulación.
 */
void leer_entrada(char* filename);

/**
 * @brief Función principal que inicia la simulación del sistema operativo.
 * 
 * Esta función verifica que se haya proporcionado el archivo de entrada en los
 * argumentos de línea de comandos. Si se cumple, llama a leer_entrada para procesar
 * los datos y ejecutar la simulación.
 * 
 * @param argc Número de argumentos proporcionados en la línea de comandos.
 * @param argv Arreglo de punteros a los argumentos de línea de comandos.
 * @return int Código de retorno. Devuelve 1 si faltan argumentos; 0 si se ejecuta correctamente.
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s --file <archivo_entrada>\n", argv[0]);
        return 1;
    }
    printf("Leyendo el archivo de entrada: %s\n", argv[2]);
    leer_entrada(argv[2]);

    printf("Simulación completada.\n");
    return 0;
}

/**
 * @brief Procesa el archivo de entrada para obtener parámetros de configuración y procesos.
 * 
 * Esta función abre el archivo de entrada en modo de lectura. Extrae el tamaño de memoria,
 * tamaño de bloque, algoritmo de asignación de memoria y algoritmo de planificación. 
 * Después, lee la lista de procesos, incluyendo su tiempo de llegada, tiempo de ejecución
 * y memoria solicitada. Simula un retardo aleatorio para cada proceso antes de imprimir
 * su información.
 * 
 * @param filename Nombre del archivo de entrada con los datos de la simulación.
 */
void leer_entrada(char* filename) {
    FILE *file = fopen(filename, "r");
    int tamano_memoria, tamano_bloque;
    char algoritmo_asignacion[3];
    char algoritmo_planificacion[10];
    int tiempo_llegada, tiempo_ejecucion, memoria_solicitada;
    int retardo;
    
    // Semilla para el generador de números aleatorios
    srand(time(NULL));
    
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    
    // Leer la primera línea con los parámetros de memoria y asignación
    fscanf(file, "%d %d %s", &tamano_memoria, &tamano_bloque, algoritmo_asignacion);
    printf("Tamaño de memoria: %d KB, Tamaño de bloque: %d KB, Asignación: %s\n",
           tamano_memoria, tamano_bloque, algoritmo_asignacion);

    // Leer la segunda línea con el algoritmo de planificación
    fscanf(file, "%s", algoritmo_planificacion);
    printf("Algoritmo de planificación: %s\n", algoritmo_planificacion);
    
    // Leer las líneas restantes con la información de cada proceso
    while (fscanf(file, "%d %d %d", &tiempo_llegada, &tiempo_ejecucion, &memoria_solicitada) == 3) {
        retardo = rand() % (3 + 1); // Genera un retardo aleatorio entre 0 y 3 segundos
        sleep(retardo); // Simula retardo en la ejecución del proceso
        
        // Imprime la información del proceso
        printf("Proceso - Llegada: %d, Ejecución: %d, Memoria: %d KB\n",
               tiempo_llegada, tiempo_ejecucion, memoria_solicitada);
    }

    fclose(file);
}
