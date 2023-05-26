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
    for (int i = 0; i < 2; i++) {
        Coordenada pos = coordTab[0 + 56 * i];
        Torre* aux = new Torre(pos, i, 0 + 56 * i);
        piezas.agregar(aux);
        pos = coordTab[7 + 56 * i];
        Torre* aux1 = new Torre(pos, i, 7 + 56 * i);
        piezas.agregar(aux1);
        pos = coordTab[2 + 56 * i];
        Alfil* aux2 = new Alfil(pos, i, 2 + 56 * i);
        piezas.agregar(aux2);
        pos = coordTab[5 + 56 * i];
        Alfil* aux3 = new Alfil(pos, i, 5 + 56 * i);
        piezas.agregar(aux3);
        pos = coordTab[1 + 56 * i];
        Caballo* aux4 = new Caballo(pos, i, 1 + 56 * i);
        piezas.agregar(aux4);
        pos = coordTab[6 + 56 * i];
        Caballo* aux5 = new Caballo(pos, i, 6 + 56 * i);
        piezas.agregar(aux5);
        pos = coordTab[3 + 56 * i];
        Reina* aux6 = new Reina(pos, i, 3 + 56 * i);
        piezas.agregar(aux6);
        pos = coordTab[4 + 56 * i];
        Rey* aux7 = new Rey(pos, i, 4 + 56 * i);
        piezas.agregar(aux7);
        for (int j = 0; j < 8; j++)
        {
            pos = coordTab[j + 8 + 40 * i];
            Peon* auxp = new Peon(pos, i, j + 8 + 40 * i);
            piezas.agregar(auxp);
        }
    }
}

void Tablero::setCoord()
{
    int k = 0;
    for (int j = 0; j < TAM_TABLERO; j++) {
        for (int i = 0; i < TAM_TABLERO; i++) {
            coordTab[k].x = (1.0001 - i * 0.25);
            coordTab[k].y = (0.99 - j * 0.25);
            k++;
            //std::cout << coordTab[k-1].x << " , " << coordTab[k-1].y << " , " << k << "\n";
        }
    }
//std:cout << coordTab[36].x << "," << coordTab[36].y;

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

    conf_modo();

    glEnable(GL_TEXTURE_2D);
    if (modo == 1)
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tablero.png").id);
    if (modo == 2)
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tablero_etsidi.png").id);
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
    sprite_selector.setCenter(1 + ((-1.0) * selector.getColumna() / 4), 1.0 - 1.0 * selector.getFila() / 4);
    sprite_selector.draw();
    glPopMatrix();
}

void Tablero::tecla_selector(unsigned char key) {
    if (key == ' ') {
        selector.setOrigen();
    } 
    selector.mover(key);
}

Selector Tablero::getSelector() {
    return selector;
}

void Tablero::mouse_selector(int x, int y) {
    selector.setOrigen();
    selector.mover_con_raton(x, y);
}

bool Tablero::casilla_vacia() {
    for (int i = 0; i < piezas.getNum(); i++) {
        if (selector.getCasilla_actual()==piezas.getPieza(i).getCasilla())
            return FALSE;
    }
    return TRUE;
}

void Tablero::dibuja_casilla_roja(bool color) {
    int fila, columna;
    sprite_cuidao.setSize(0.25, 0.25);
    for (int i = 0; i < piezas.getNum(); i++) {
        if ((piezas.getPiezap(i)->getTipo() == 5)&&(color==piezas.getPiezap(i)->getColor())) {
            columna = piezas.getPiezap(i)->getCasilla() % 8;
            fila = (piezas.getPiezap(i)->getCasilla() - columna) / 8;
        }
    }
    sprite_cuidao.setCenter(1 + ((-1.0) * columna / 4), 1.0 - 1.0 * fila / 4);
    sprite_cuidao.draw();
    glPopMatrix();
}
