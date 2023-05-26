#include "Peon.h"
#include<iostream>

Peon::Peon(Coordenada posicion_, int color_, int casilla_)
{
	conf_modo();

	if (modo == 1)
		sprite3.setSize(0.25, 0.25);
	if (modo == 2)
		sprite3_1.setSize(0.25, 0.25);

	if (modo == 1)
		sprite9.setSize(0.25, 0.25);
	if (modo == 2)
		sprite9_1.setSize(0.25, 0.25);

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

		if (modo == 1)
			sprite3.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite3_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite3.draw();
		if (modo == 2)
			sprite3_1.draw();

		glPopMatrix();
	}
	if (color == 1) {

		if (modo == 1)
			sprite9.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite9_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite9.draw();
		if (modo == 2)
			sprite9_1.draw();

		glPopMatrix();
	}
}

void Peon::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	
	if (
		(
		
		((((dif%7==0)&&(pieza_enemiga_pieza==TRUE))||((dif%8==0)&&pieza_enemiga_pieza==FALSE)|| ((dif % 9 == 0) && (pieza_enemiga_pieza == TRUE)))
		&&((dif < 10) && ((dif>0)&&(color == 0))||((dif > -10)) && (dif < 0) && (color == 1)))
		||
		((dif==16)&&(color==0) || (dif==-16)&&(color==1)) && (pieza_movida == 0)
		)
		&&(dif!=0)
		) {
		pieza_enemiga_pieza = FALSE;
		b = TRUE;
		ETSIDI::play("sonidos/mov.wav");

	}
	else {
		pieza_enemiga_pieza = FALSE;
		b = FALSE;
	}
}

