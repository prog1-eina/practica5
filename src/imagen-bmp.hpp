/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: Miguel Ángel Latre y Rafael Tolosana
 * Ultima revisión: 20 de noviembre de 2020
 * Resumen: Fichero de interfaz «imagen.hpp» de un módulo denominado
 *          «imagen» para trabajar con imágenes BMP
 *          en la 5.ª práctica.
\******************************************************************************/
#include <string>
using namespace std;

const int ANCHO = 800;
const int ALTO = 800;
const unsigned int TAM_CABECERA_1 = 18;
const unsigned int TAM_CABECERA_2 = 28;

struct Pixel {
    char rojo, verde, azul;
};

struct Imagen {
    char cabecera1[TAM_CABECERA_1];
    char cabecera2[TAM_CABECERA_2];
    unsigned int ancho, alto;
    Pixel pixels[ANCHO][ALTO];
};

/*
 * Pre:  «nombreFichero» es un fichero binario en formato BMP 
 * Post: Si se ha encontrado el fichero y este tiene unas dimensiones correctas,
 *       tras ejecutar este procedimiento, «imagen» almacena en memoria
 *       la imagen almacenada en un fichero binario en formato BMP y la función
 *       ha devuelto true. En caso contrario, ha devuelto false y ha escrito en
 *       la pantalla un mensaje de error indicando la causa del mismo.
 */
bool leerImagen(const string nombreFichero, Imagen& imagen);


/*
 * Pre:  ---
 * Post: Tras ejecutar este procedimiento, almacena en disco en un fichero de 
 *       nombre «nombreFichero» la imagen BMP de «imagen».
 */
void guardarImagen(const string nombreFichero, Imagen imagen);
