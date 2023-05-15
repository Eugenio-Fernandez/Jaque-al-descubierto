#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class Menu
{
	Sprite* menu1 = new Sprite("imagenes/menunuevapartida.png", 4.0, 4.0, 8.0, 8.0);
	Sprite* menu2 = new Sprite("imagenes/menusalir.png", 4.0, 4.0, 8.0, 8.0);
	//bool inicio;
	int modo1, modo2;
public:
	Menu();
	~Menu();
	void dibuja();
	//int getTecla(unsigned char);

	void inicializa();
	void tecla(unsigned char key);
	void tecla2(unsigned char key);
};