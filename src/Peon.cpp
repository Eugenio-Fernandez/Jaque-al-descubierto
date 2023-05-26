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
	
	if ((origen<16)&&(color==0)) {
		setPieza_nomovida();
	}	

	if ((origen > 47) && (color == 1)) {
		setPieza_nomovida();
	}


	if (
		(
		((((dif%7==0)&&(pieza_enemiga_pieza==TRUE))||((dif%8==0)&&pieza_enemiga_pieza==FALSE)|| ((dif % 9 == 0) && (pieza_enemiga_pieza == TRUE)))
		&&((dif<10)&&(dif>-10))&&(((dif>0)&&(color == 0))||((dif < 0) && (color == 1))))
		||
		(dif % 16 == 0)&&(pieza_movida==0)
		)
		&&(dif!=0)
		) {
		pieza_enemiga_pieza = FALSE;
		setPieza_movida();
		std::cout << "Movida\n";
		b = TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		pieza_enemiga_pieza = FALSE;
		b = FALSE;
	}
}

/*
if (
		(dif % 8 == 0) && ((dif < 10) && (dif > -10)) && (((dif > 0) && (color == 0)) || ((dif < 0) && (color == 1)))
		||
		((dif % 16 == 0) && ((origen >= 8) && (origen <= 15)) || ((origen >= 48) && (origen <= 55)))
		) {
		b = TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		b = FALSE;

	}
*/
