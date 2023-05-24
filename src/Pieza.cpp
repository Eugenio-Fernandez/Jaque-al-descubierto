#pragma once
#include <vector>
#include "Coordenada.h"
#include "ETSIDI.h"
#include "Interaccion.h"
using ETSIDI::SpriteSequence;

using namespace std;

enum class Color {
    Blanco,
    Negro
};

class Pieza {
    friend class Interaccion;
    Coordenada posicion;
protected:
    int color;// 0 blanca 1 negra
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
    virtual void mueve(Coordenada origen, Coordenada destino);
    Coordenada getPos();
};
