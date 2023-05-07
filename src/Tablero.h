#pragma once

#include "Pieza.h"
#include "Coordenada.h"
#include "Casilla.h"

const int TAM_TABLERO = 8;

class Tablero {
private:
    int tablero[8][8];
    Pieza* casillas[TAM_TABLERO][TAM_TABLERO];
public:
    Tablero();
    ~Tablero();
    //saber posición de la pieza
    Pieza* obtenerPosicionPieza(Coordenada posicion);
    // colocar la pieza en una posición determinada (al inicio)
    void colocarPieza(Coordenada posicion, Pieza* pieza);
    //mover las piezas de ua coordenada a otra
    bool moverPieza(Coordenada origen, Coordenada destino);
    //comprobar que la casilla está dentro del tablero
    bool esCoordenadaValida(Coordenada coordenada) const;
};

