#include <GL/glut.h>
#include "Coordenada.h"
#include "Tablero.h"
#include <string>
#include <iostream>

using namespace std;

const int TAM_CASILLA = 75;
void menu(int value) {
    switch (value) {
    case 1:
        std::cout << "Has seleccionado: Nueva partida" << std::endl;
        // Aquí va el código para iniciar una nueva partida
        break;
    case 2:
        std::cout << "Has seleccionado: Cargar partida" << std::endl;
        // Aquí va el código para cargar una partida guardada
        break;
    case 3:
        std::cout << "Has seleccionado: Guardar partida" << std::endl;
        // Aquí va el código para guardar la partida actual
        break;
    case 4:
        std::cout << "Has seleccionado: Salir del juego" << std::endl;
        // Aquí va el código para salir del juego
        exit(0);
        break;
    }
}
void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    // Dibujar el borde del tablero
    glColor3f(0.4f, 0.2f, 0.0f);
    glRecti(-75, -75, TAM_CASILLA * 10, TAM_CASILLA * 10);

    // Dibujar posiciones del tablero
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int i = 0; i < TAM_TABLERO; i++) {

        char letra = 'a';

        for (int j = 0; j < 2; j = j++) {

            glRasterPos2i((i + 1) * TAM_CASILLA + TAM_CASILLA / 2, j * TAM_CASILLA * (TAM_TABLERO + 1) + TAM_CASILLA / 2);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letra + i);
            glRasterPos2i(TAM_CASILLA / 2 + j * TAM_CASILLA * (TAM_TABLERO + 1), (i + 1) * TAM_CASILLA + TAM_CASILLA / 2);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '8' - i);
        }
    }


    // Dibujar el tablero
    for (int fila = 1; fila <= TAM_TABLERO; fila++) {

        for (int columna = 1; columna <= TAM_TABLERO; columna++) {

            if ((fila + columna) % 2 == 0) {
                glColor3f(0.8f, 0.6f, 0.4f);
            }
            else {
                glColor3f(0.6f, 0.4f, 0.2f);
            }

            glRecti(columna * TAM_CASILLA, fila * TAM_CASILLA,
                (columna + 1) * TAM_CASILLA, (fila + 1) * TAM_CASILLA);
        }
    }

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(TAM_CASILLA * TAM_TABLERO, TAM_CASILLA * TAM_TABLERO);
    glutCreateWindow("Ajedrez");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, TAM_CASILLA * TAM_TABLERO + 150, TAM_CASILLA * TAM_TABLERO + 150, 0, -1, 1);
    // Crear el menú
    glutCreateMenu(menu);
    glutAddMenuEntry("Nueva partida", 1);
    glutAddMenuEntry("Cargar partida", 2);
    glutAddMenuEntry("Guardar partida", 3);
    glutAddMenuEntry("Salir", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
