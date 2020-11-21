/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: ¡¡¡PONED AQUÍ VUESTROS NOMBRES!!!
 * Ultima revisión: ¡¡¡¡!!!!
 * Resumen: ¡¡¡¡!!!!
\******************************************************************************/
#include <iostream>
#include "juego-vida.hpp"
using namespace std;

/*
 * Pre:  ---
 * Post: Borra la parte visible del terminal y mueve el cursor a la primera
 *       fila y la primera columna, de forma que la siguiente instrucción de 
 *       escritura en pantalla escriba desde el inicio de la parte visible del
 *       terminal.
 */
void borrarPantalla() {
    cout << "\033[2J";
}

/*
 * Pre:  ---
 * Post: Sube el cursor de escritura del terminal «lineas» líneas, sin borrar
 *       el contenido que ya esté escrito en el terminal.
 */
void subirCursor(const unsigned int lineas) {
    cout << "\033[" << lineas << "A";
}

