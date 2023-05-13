#include "Peon.h"

//Peon::Peon(Color color, Coordenada posicion) : Pieza(color, posicion) {}
//Peon::~Peon() {}

bool Peon::esMovimientoValido(Coordenada origen, Coordenada destino, Tablero& tablero) const {
    
    int direccion = (obtenerColor() == Color::Blanco) ? 1 : -1;
    int filaOrigen = origen.fila;
    int filaDestino = destino.fila;
    int columnaOrigen = origen.columna;
    int columnaDestino = destino.columna;

    // Validar que el movimiento sea diagonal para capturar una pieza del oponente
    if (columnaOrigen != columnaDestino && filaOrigen + direccion == filaDestino) {
        
        Pieza* piezaEnDestino = tablero.obtenerPosicionPieza(destino);
        
        if (piezaEnDestino != nullptr && piezaEnDestino->obtenerColor() != obtenerColor()) {
            
            return true;
        }
    }
    // Validar que el movimiento sea hacia adelante
    else if (columnaOrigen == columnaDestino && filaOrigen + direccion == filaDestino) {
    // Validar que el peón no tenga piezas bloqueándolo
        if (tablero.obtenerPosicionPieza(destino) == nullptr) {
            return true;
        }
    }
    return false;
}


vector<Coordenada> Peon::obtenerTodasLasJugadasPosibles(Tablero& tablero) const {
    
    vector<Coordenada> jugadasPosibles;

    int direccion = (obtenerColor() == Color::Blanco) ? 1 : -1;
    int fila = obtenerPosicionActual().fila;
    int columna = obtenerPosicionActual().columna;
    
    // Agregar movimiento hacia adelante
    Coordenada posibleJugada;
    posibleJugada.fila = fila + direccion;
    posibleJugada.columna = columna;
    
    if (tablero.esCoordenadaValida(posibleJugada) && tablero.obtenerPosicionPieza(posibleJugada) == nullptr) {
        
        jugadasPosibles.push_back(posibleJugada);
    }

    // Agregar movimientos diagonales para capturar piezas del oponente
    posibleJugada.fila = fila + direccion;
    posibleJugada.columna = columna + 1;

    if (tablero.esCoordenadaValida(posibleJugada)) {
        
        Pieza* piezaEnDestino = tablero.obtenerPosicionPieza(posibleJugada);
        
        if (piezaEnDestino != nullptr && piezaEnDestino->obtenerColor() != obtenerColor()) {
            
            jugadasPosibles.push_back(posibleJugada);
        }
    }
    
    posibleJugada.fila = fila + direccion;
    posibleJugada.columna = columna + 1;

    if (tablero.esCoordenadaValida(posibleJugada)) {
        
        Pieza* piezaEnDestino = tablero.obtenerPosicionPieza(posibleJugada);
        
        if (piezaEnDestino != nullptr && piezaEnDestino->obtenerColor() != obtenerColor()) {
            jugadasPosibles.push_back(posibleJugada);
        }
    }
    return jugadasPosibles;
}
