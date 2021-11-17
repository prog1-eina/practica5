/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: Miguel Ángel Latre y Rafael Tolosana
 * Modificado por: ¡¡¡PON AQUÍ TU NOMBRE!!!
 * Ultima revisión: 21 de noviembre de 2020
 * Resumen: Fichero de implementación del módulo principal del programa que 
 *          manipula imágenes BMP en la 5ª práctica.
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make bmp
 *       o, en Windows,
 *           mingw32-make bmp
 *       o ejecutar la tarea "Compilar «bmp»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/bmp
 *       o, en Windows,
 *           bin\bmp.exe
 *       o ejecutar la tarea "Ejecutar «bmp»" de VSC.
\******************************************************************************/
#include <iostream>
#include <string>
#include "imagen-bmp.hpp"
using namespace std;

int main() {
    static Imagen img;
    string nombreFichero = "datos/prog1.bmp";
   
    if (leerImagen(nombreFichero, img)) {
        guardarImagen("datos/imagen-generada.bmp", img);
        return 0;
    }
    else {
        return 1;
    }
}