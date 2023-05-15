#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "cstdlib"
#include "Tablero.h"
using ETSIDI::Sprite;
Tablero tablero2;
Menu::Menu()
{
	//inicio = false;
	menu1->setSize(2.0,2.0);
	menu1->setPos(3.0, 3.0);
	menu2->setSize(2.0, 2.0);
	menu2->setPos(3.0, 3.0);
}

Menu::~Menu()
{
	menu1->~Sprite();
}

void Menu::dibuja()
{
	menu1->draw();
	
	if (modo1 == 1)menu1->draw();
	if (modo1 == 2)menu2->draw();

	if (modo1 == 1 && modo2==1)
	{
		tablero2.dibuja();
	    tablero2.dibuja_selector();
	}

	if (modo1 == 2 && modo2==1)
	{
		exit(0);
	}
}



//Funcion para inicializar el selector
void Menu::inicializa() {
	Selector selector;
}

//Funcion para realizar el movimiento del selector por las casillas del tablero
void Menu::tecla(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_DOWN:
		modo1 = 2;
		break;
	case GLUT_KEY_UP:
		modo1 = 1;
	}
}

void Menu::tecla2(unsigned char key) {
	switch (key)
	{
	case 13:
		modo2 = 1;
		break;
	}
}

