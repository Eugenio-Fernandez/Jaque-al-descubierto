#include "Peon.h"
#include<iostream>

Peon::Peon(Coordenada posicion_, int color_, int casilla_)
{
	sprite3.setSize(0.25, 0.25);
	sprite9.setSize(0.25, 0.25);
	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 4;
}

Peon::~Peon()
{

}

void Peon::dibuja() {
	
	if (color == 0) {
		sprite3.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite3.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite9.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite9.draw();
		glPopMatrix();
	}
}

void Peon::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	std::cout << "Pieza_enemiga: " << pieza_enemiga << "  color: " << color << endl;
	if ((((dif%7==0)&&(pieza_enemiga==TRUE))||((dif%8==0)&&pieza_enemiga==FALSE)|| ((dif % 9 == 0) && (pieza_enemiga == TRUE)))
		&&((dif<10)&&(dif>-10))&&(((dif>0)&&(color == 0))||((dif < 0) && (color == 1)))) {
		pieza_enemiga = FALSE;
		b = TRUE;
	}
	else {
		pieza_enemiga = FALSE;
		b = FALSE;
	}
	
}