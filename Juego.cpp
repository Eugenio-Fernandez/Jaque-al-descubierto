#include "freeglut.h"
#include "Coordenada.h"
#include "Tablero.h"
#include <iostream>
#include <string>
using namespace std;

void Menu();
void OnDraw(void);

const int TAM_CASILLA = 75;

Tablero tablero;

int main(int argc,char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Jaque al descubierto");
	glClearColor(0, 0, 1, 1);
	glColor3f(1.f, 0, 0);
	glOrtho(800, 0, 800, 0, -1, 1);
	
	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	
	Menu();
	tablero.setCoord();
	glutMainLoop();

    	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	Menu();
	tablero.dibuja();
	//pieza.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
	
}

void Menu()
{

    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla
    
    // Dibuja el título del juego
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1, 1, 1);
    glRasterPos2f(250, 400);
    string titulo = "Jaque al descubierto";
    for (int i = 0; i < titulo.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, titulo[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    // Dibuja las opciones del menú
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1, 1, 1);
    glRasterPos2f(250, 300);
    string opcion1 = "1. Nueva partida";
    for (int i = 0; i < opcion1.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opcion1[i]);
    }
    glRasterPos2f(250, 250);
    string opcion2 = "2. Salir";
    for (int i = 0; i < opcion2.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opcion2[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    // Dibuja todo en la pantalla
    glutSwapBuffers();
}

// Función que maneja el evento de selección de una opción del menú
void menu(int opcion) 
{
    switch(opcion) 
    {
        case 1:
            // Pedimos los nombres de los jugadores
            /*string nombreJugador1, nombreJugador2;
            cout << "Ingrese el nombre del jugador 1: ";
            cin >> nombreJugador1;
            cout << "Ingrese el nombre del jugador 2: ";
            cin >> nombreJugador2;*/
            
            // Iniciamos el juego
            // Aquí iría el código para el juego 
            break;
        case 2:
            // Salimos del programa
            exit(0);
            break;
        default:
            // Si el usuario ingresa una opción inválida, no hacemos nada
            break;
    }
}
