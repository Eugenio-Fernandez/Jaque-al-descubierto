#include "Reina.h"
#include<iostream>

Reina::Reina(Coordenada posicion_, int color_, int casilla_)
{
	sprite4.setSize(0.25, 0.25);
	sprite10.setSize(0.25, 0.25);
	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 3;
}

Reina::~Reina()
{

}

void Reina::dibuja() {
	if (color == 0) {
		sprite4.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite4.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite10.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite10.draw();
		glPopMatrix();
	}
}

void Reina::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	
	std::cout << "Reina\n";
	if (
		(dif%7==0)
		||
		(dif%8==0)
		||
		(dif%9==0)
		||
		((((dif > -8) && (dif < 8)) && ((((7 - origen % 8) >= dif) && (dif > 0)) || (((origen % 8) >= -dif) && (dif < 0)))))
		) {
		b= TRUE;
		ETSIDI::play("sonidos/mov.wav");
		
	}
	else {
		b= FALSE;
		std::cout << "no valido\n";
	}
}

