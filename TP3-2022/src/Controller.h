/*
 * Controller.h
 *
 *  Created on: 9 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Muestra el menu y devuelve
 *
 * @return Opcion de menu elegido
 */
int mostrarMenu(void);


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeTexto(char* path , LinkedList* pArrayListPassenger);


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeBinario(char* path , LinkedList* pArrayListPassenger);


/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_altaPasajero(LinkedList* pArrayListPassenger);


/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_modificarPasajero(LinkedList* pArrayListPassenger);


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_bajaPasajero(LinkedList* pArrayListPassenger);


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListarPasajeros(LinkedList* pArrayListPassenger);


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ordenarPasajeros(LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_GuardarComoTexto(char* path , LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_GuardarComoBinario(char* path , LinkedList* pArrayListPassenger);

#endif /* CONTROLLER_H_ */
