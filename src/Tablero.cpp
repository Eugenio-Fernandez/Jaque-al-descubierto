#include "Tablero.h"
#include <stdio.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>
using namespace std;

/*Blancas + y negras -
Alfil 1
Caballo 2
Peón 3
Reina 4
Rey 5
Torre 6
Vacía 0*/

int Tablero::start[8][8] = { {6,2,1,5,4,1,2,6} , {3,3,3,3,3,3,3,3} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {-3,-3,-3,-3,-3,-3,-3,-3} , {-6,-2,-1,-5,-4,-1,-2,-6} };

Tablero::Tablero() {
    // Inicializar las casillas del tablero
    for (int fila = 0; fila < TAM_TABLERO; fila++) {
        for (int columna = 0; columna < TAM_TABLERO; columna++) {
            casillas[fila][columna] = nullptr;
        }
    }
}

void Tablero::inicio()
{
    for (int i = 0; i < TAM_TABLERO; i++) {
        for (int j = 0; j < TAM_TABLERO; j++) {
            tablero[i][j] = start[i][j];
        }
    }
}

void Tablero::setCoord()
{
    for (int i = 0; i < TAM_TABLERO; i++) {
        for (int j = 0; j < TAM_TABLERO; j++) {
            coordTab[i].x = (1.0001 - i * 0.25);
            coordTab[j].y = (0.99 - j * 0.25);
        }
    }
}

Tablero::~Tablero() {
    // Eliminar todas las piezas del tablero
    for (int fila = 0; fila < TAM_TABLERO; fila++) {
        for (int columna = 0; columna < TAM_TABLERO; columna++) {
            if (casillas[fila][columna] != nullptr) {
                delete casillas[fila][columna];
                casillas[fila][columna] = nullptr;
            }
        }
    }
}

void Tablero::dibuja() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tablero.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 1); glVertex2f(-1,-1);
    glTexCoord2d(1, 1); glVertex2f(1, -1);
    glTexCoord2d(1, 0); glVertex2f(1, 1);
    glTexCoord2d(0, 0); glVertex2f(-1, 1);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void Tablero::dibuja_selector() {
    sprite_selector.setSize(0.25, 0.25);
    sprite_selector.setCenter(1 + ((-1.0) * selector.getFila() / 4), 1.0 - 1.0 * selector.getColumna() / 4);
    sprite_selector.draw();
    glPopMatrix();
}

void Tablero::tecla_selector(unsigned char key) {
    selector.mover(key);
}