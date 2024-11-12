/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: Miguel Ángel Latre y Rafael Tolosana
 * Última revisión: 12 de noviembre de 2024
 * Resumen: Fichero de interfaz «imagen.hpp» de un módulo denominado
 *          «imagen» para trabajar con imágenes BMP
 *          en la 5.ª práctica.
\******************************************************************************/

#pragma once

#include <string>
using namespace std;

const unsigned MAX_ANCHO = 8192;
const unsigned MAX_ALTO = 8192;
const unsigned TAM_CABECERA_1 = 18;
const unsigned TAM_CABECERA_2 = 28;

struct Pixel {
    char rojo, verde, azul;
};

struct Imagen {
    unsigned ancho, alto;
    Pixel pixels[MAX_ALTO][MAX_ANCHO];
    char cabeceraParte1[TAM_CABECERA_1];
    char cabeceraParte2[TAM_CABECERA_2];
};

/*
 * Pre:  «nombreFichero» es un fichero binario en formato BMP.
 * Post: Si existe el fichero «nombreFichero» y este tiene unas dimensiones
 *       correctas, tras ejecutar este procedimiento, «imagen» almacena en
 *       memoria la imagen almacenada en un fichero binario en formato BMP y
 *       «lecturaOk» vale «true». En caso contrario, escribe en la pantalla un
 *       mensaje de error indicando la causa del mismo «lecturaOk» vale «false».
 */
void leerImagen(const string nombreFichero, Imagen &imagen, bool &lecturaOk);


/*
 * Pre:  ---
 * Post: Tras ejecutar este procedimiento, almacena en disco en un fichero de 
 *       nombre «nombreFichero» la imagen BMP de «imagen».
 */
void guardarImagen(const string nombreFichero, const Imagen &imagen);
