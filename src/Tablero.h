#pragma once
#include "Pieza.h"
#include "Coordenada.h"
#include "ETSIDI.h"
#include "Selector.h"
#include "ListaPiezas.h"
//#include "Interaccion.h"
using ETSIDI::SpriteSequence;

const int TAM_TABLERO = 8;

class Tablero
{
private:
    Menu menu;
    int modo;
    int tablero[TAM_TABLERO][TAM_TABLERO];
    Pieza* casillas[TAM_TABLERO][TAM_TABLERO];
    SpriteSequence sprite_selector{ "imagenes/Selector.png",5 };
    SpriteSequence sprite_cuidao{ "imagenes/cuidao.png",5 };
    Selector selector;
    //Interaccion interaccion;

public:
    ListaPiezas piezas;
    static int start[TAM_TABLERO][TAM_TABLERO];
    Coordenada coordTab[64];
    Tablero();
    void setCoord();
    virtual ~Tablero();
    void dibuja();
    void inicio();
    void dibuja_selector();
    void tecla_selector(unsigned char key);
    void mouse_selector(int x, int y);
    bool casilla_vacia();
    void dibuja_casilla_roja(bool color);
    Selector getSelector();
    void conf_modo() { modo = menu.getMarcha(); }
};

