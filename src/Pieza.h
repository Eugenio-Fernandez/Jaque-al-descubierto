#pragma once
#include <vector>
#include "Coordenada.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

using namespace std;

enum class Color {
    Blanco,
    Negro
};

// tipo
/*
Alfil = 1
Caballo = 2
Dama = 3
Peon = 4
Rey = 5
Torre = 6
*/

class Pieza {
    
protected:
    int casilla;
    int color;// 0 blanca 1 negra
    int tipo;
    bool pieza_movida = FALSE;
    bool pieza_enemiga = FALSE;
    Coordenada posicion;
    SpriteSequence sprite1{ "imagenes/AlfilBlanco.png",1 };
    SpriteSequence sprite2{ "imagenes/CaballoBlanco.png",1 };
    SpriteSequence sprite3{ "imagenes/PeonBlanco.png",1 };
    SpriteSequence sprite4{ "imagenes/ReinaBlanca.png",1 };
    SpriteSequence sprite5{ "imagenes/ReyBlanco.png",1 };
    SpriteSequence sprite6{ "imagenes/TorreBlanca.png",1 };
    SpriteSequence sprite7{ "imagenes/AlfilNegro.png",1 };
    SpriteSequence sprite8{ "imagenes/CaballoNegro.png",1 };
    SpriteSequence sprite9{ "imagenes/PeonNegro.png",1 };
    SpriteSequence sprite10{ "imagenes/ReinaNegra.png",1 };
    SpriteSequence sprite11{ "imagenes/ReyNegro.png",1 };
    SpriteSequence sprite12{ "imagenes/TorreNegra.png",1 };
public:
    Pieza();
    //virtual ~Pieza();
    virtual void dibuja();
    //virtual void mueve(Coordenada origen, Coordenada destino);
    void mueve(Coordenada destino);
    void setCasilla(int casilla_);
    int getCasilla() { return casilla; }
    int getColor() { return color; }
    int getTipo() { return tipo; }
    Coordenada getPos();
    virtual void movimientovalido(int origen, int destino, bool &b){}
    bool getPieza_movida() { return pieza_movida; }
    void setPieza_movida() { pieza_movida = TRUE; }
    void setPieza_enemiga(bool pieza_enemiga_) { pieza_enemiga = pieza_enemiga_; }
};