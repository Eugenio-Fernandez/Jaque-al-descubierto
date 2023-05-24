#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

Menu::Menu()
{
	menu1->setSize(8.0, 8.0);
	menu1->setPos(4.0, 4.0);
	menu2->setSize(8.0, 8.0);
	menu2->setPos(4.0, 4.0);
}

Menu::~Menu() {
	menu1->~Sprite();
	menu2->~Sprite();
}

void Menu::dibuja() {
	if (pantalla == 0) {
		menu1->draw();
	}

	if (pantalla == 1) {
		menu2->draw();
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