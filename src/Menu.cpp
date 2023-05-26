#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "cstdlib"
#include "Tablero.h"
#include <iostream>
using ETSIDI::Sprite;
Tablero tablero2;

Menu::Menu()
{
	menu1->setSize(2.0, 2.0);
	menu1->setPos(4.0, 4.0);
	menu2->setSize(2.0, 2.0);
	menu2->setPos(4.0, 4.0);
	menu3->setSize(2.0, 2.0);
	menu3->setPos(4.0, 4.0);
	menu4->setSize(2.0, 2.0);
	menu4->setPos(4.0, 4.0);
}

Menu::~Menu() {
	menu1->~Sprite();
	menu2->~Sprite();
	menu3->~Sprite();
	menu4->~Sprite();
}
int Menu::dibuja()
{
	int a = 0; // Inicializamos la variable a con un valor por defecto

	if (inicio == 0) {
		if (modo3 == 0) {
			if (modo1 == 1) {
				//menu1->draw();
			}
			else if (modo1 == 2) {
				//menu2->draw();
			}

			if (modo2 == 1 && modo1 == 2) {
				inicio = 1;
			}
			else if (modo2 == 1 && modo1 == 1) {
				modo2 = 0;
				modo3 = 1;
			}
		}

		if (modo3 == 1) {

			if (modo1 == 1) {
				//menu3->draw();

			}
			else if (modo1 == 2) {
				//menu4->draw();
				a = 2;
			}
			if (modo2 == 1) {
				std::cout << "esto" << std::endl;
				ETSIDI::play("sonidos/cr7.wav");
				marcha = 1;
				modo3 = 3;
				delete menu1;
				delete menu2;
				delete menu3;
				delete menu4;
			}
		}
	}
	else if (inicio == 1) {
		exit(0);
	}

	if (modo2 == 1) {
		if (modo1 == 1) {
			marcha = 1;
			return 1;
		}
		else if (modo1 == 2) {
			return 2;
		}
	}

	// Forzar manualmente el valor de retorno para probar modos, no ha sido correctamente implementado
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	////////////////////////////////////////

	return 2; // 1 --> Modo Clásico; 2 --> Modo ETSIDI

	////////////////////////////////////////
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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

void op(int value) {

	switch (value) {
	case 1:
		std::cout << "Has seleccionado: Salir del juego" << std::endl;
		// Aquí va el código para salir del juego
		exit(0);
		break;
	
	}

}
