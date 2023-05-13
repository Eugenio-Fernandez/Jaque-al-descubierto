#pragma once
#include "Pieza.h"
#include "Tablero.h"

class Peon : public Pieza {
public:
    Peon(Color color, Coordenada posicion) : Pieza(color, posicion) {};
    ~Peon() {};
    
    // Implementación de la validación de movimiento para el peón
    bool esMovimientoValido(Coordenada origen, Coordenada destino, Tablero& tablero) const ;
    // Implementación de la obtención de todas las jugadas posibles para el peón
    vector<Coordenada> obtenerTodasLasJugadasPosibles(Tablero& tablero) const ;
    void mover(unsigned char key);
};



