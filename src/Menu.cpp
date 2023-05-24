#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "cstdlib"
#include "Tablero.h"
using ETSIDI::Sprite;
Tablero tablero2;
Menu::Menu()
{

	menu1->setSize(2.0, 2.0);
	menu1->setPos(4.0, 4.0);
	menu2->setSize(2.0, 2.0);
	menu2->setPos(4.0, 4.0);
}

Menu::~Menu()
{
	menu1->~Sprite();
	menu2->~Sprite();
}

void Menu::dibuja()
{
	if(inicio == 0) {
		
		if (modo1 == 1)menu1->draw();
		if (modo1 == 2)menu2->draw();
		if (modo1 == 1 && modo2 == 1) {
			
			ETSIDI::play("sonidos/cr7.wav");
			modo1 = 0;
			inicio = 1;
			delete menu1;
			delete menu2;
		}
		
		if (modo1 == 2 && modo2 == 1 && inicio ==0) {
			exit(0);
		}
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


void Menu::flecha(int key) {

	if (start == false) {
		switch (key) {
		case GLUT_KEY_UP:
			if (pantalla == 0) {
				pantalla = 1;
			}
			break;

		case GLUT_KEY_DOWN:
			if (pantalla == 1) {
				pantalla = 0;
			}
			break;
		}
	}
}
