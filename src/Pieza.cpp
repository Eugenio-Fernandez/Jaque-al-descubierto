#include "Pieza.h"
#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include<iostream>

using ETSIDI::SpriteSequence;


Pieza::Pieza(){

}

void Pieza::dibuja() {
	
}


Coordenada Pieza::getPos() {
	return posicion;
}

void Pieza::mueve(Coordenada destino) {
	posicion.x = destino.x;
	posicion.y = destino.y;
	std::cout << "hola mundo" << endl;
}

void Pieza::setCasilla(int casilla_) {
	casilla = casilla_;
}

