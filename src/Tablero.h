#pragma once
#include "Pieza.h"
#include "Coordenada.h"
#include "Casilla.h"
#include "ETSIDI.h"
#include "Selector.h"
using ETSIDI::SpriteSequence;

const int TAM_TABLERO = 8;

class Tablero
{
private:
    int tablero[TAM_TABLERO][TAM_TABLERO];
    Pieza* casillas[TAM_TABLERO][TAM_TABLERO];
    SpriteSequence sprite_selector{ "imagenes/Selector.png",5 };
    Selector selector;
public:
    static int start[TAM_TABLERO][TAM_TABLERO];
    Coordenada coordTab[32];
    Tablero();
    void setCoord();
    virtual ~Tablero();
    void dibuja();
    void inicio();
    void dibuja_selector();
    void tecla_selector(unsigned char key);
};

