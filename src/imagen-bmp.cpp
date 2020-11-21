/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: Miguel Ángel Latre y Rafael Tolosana
 * Ultima revisión: 19 de noviembre de 2020
 * Resumen: Fichero de interfaz «imagen.hpp» de un módulo denominado
 *          «imagen» para trabajar con imágenes BMP
 *          en la 5.ª práctica.
\******************************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include "imagen-bmp.hpp"
using namespace std;


/*
 * Pre:  «nombreFichero» es un fichero binario en formato BMP 
 * Post: Si se ha encontrado el fichero y este tiene unas dimensiones correctas,
 *       tras ejecutar este procedimiento, «imagen» almacena en memoria
 *       la imagen almacenada en un fichero binario en formato BMP y la función
 *       ha devuelto true. En caso contrario, ha devuelto false y ha escrito en
 *       la pantalla un mensaje de error indicando la causa del mismo.
 */
bool leerImagen(const string nombreFichero, Imagen& imagen) {
    ifstream infile(nombreFichero, ios::binary);
    if(infile.is_open()){
        infile.read(imagen.cabecera1, TAM_CABECERA_1);
        if (imagen.cabecera1[0] == 'B' && imagen.cabecera1[1] == 'M') {
            infile.read(reinterpret_cast<char*>(&imagen.ancho), sizeof(int));
            infile.read(reinterpret_cast<char*>(&imagen.alto), sizeof(int));
            infile.read(imagen.cabecera2, TAM_CABECERA_2); 
            for(unsigned int i = 0; i < imagen.alto; i++){
                for(unsigned int j = 0; j < imagen.ancho; j++){
                    infile.read(&imagen.pixels[i][j].rojo, sizeof(char));
                    infile.read(&imagen.pixels[i][j].verde, sizeof(char));
                    infile.read(&imagen.pixels[i][j].azul, sizeof(char));
                }
            }
            cout << "Imagen \"" << nombreFichero << "\" leída con éxito." << endl;
            infile.close();
            return true;
        }
        else {
            cout << "El fichero \"" << nombreFichero 
                 << "\" no tiene el formato BMP." << endl;
            return false;
        }
    }
    else {
        cout << "No se ha encontrado el fichero \"" << nombreFichero << "\"."
             << endl;
        return false;
    }
}


/*
 * Pre:  ---
 * Post: Tras ejecutar este procedimiento, almacena en disco en un fichero de 
 *       nombre «nombreFichero» la imagen BMP de «imagen».
 */
void guardarImagen(const string nombreFichero, Imagen imagen) {
    ofstream outFile(nombreFichero, ios::binary);
    if (outFile.is_open()) {
        outFile.write(imagen.cabecera1, TAM_CABECERA_1);
        outFile.write(reinterpret_cast<char*>(&imagen.ancho), sizeof(int));
        outFile.write(reinterpret_cast<char*>(&imagen.alto), sizeof(int));
        outFile.write(imagen.cabecera2, TAM_CABECERA_2); 
        for(unsigned int i = 0; i < imagen.alto; i++){
            for(unsigned int j = 0; j < imagen.ancho; j++){
                outFile.write(&imagen.pixels[i][j].rojo, sizeof(char));
                outFile.write(&imagen.pixels[i][j].verde, sizeof(char));
                outFile.write(&imagen.pixels[i][j].azul, sizeof(char));
            }
        }
        cout << "Imagen \"" << nombreFichero << "\" creada con éxito." << endl;
    }
    else {
        cerr << "No se ha podido crear la imagen \"" << nombreFichero << "\"."
             << endl;
    }
    outFile.close();
}

