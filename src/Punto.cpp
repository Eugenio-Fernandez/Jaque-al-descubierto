#include "Punto.h"
#include "Coordenada.h"
#include "Interaccion.h"
#include <iostream>

#define TAM_TABLERO 8
Punto::Punto() {
	sprite_punto.setSize(0.07, 0.07);
}

void Punto::dibuja_punto(Coordenada coordenada)
{
	sprite_punto.setCenter(coordenada.x,coordenada.y);
	glPushMatrix();
	sprite_punto.draw();
	glPopMatrix();
}

void Punto::setCoord()
{
    int k = 0;
    for (int j = 0; j < TAM_TABLERO; j++) {
        for (int i = 0; i < TAM_TABLERO; i++) {
            coordPunto[k].x = (0.908 - i * 0.25);
            coordPunto[k].y = (0.91 - j * 0.25);
            k++;
        }
    }
}

Coordenada Punto::getCoord(int casilla)
{
	return coordPunto[casilla];
}

void Punto::mover_punto(Selector selector, ListaPiezas& piezas)
{
	int casilla_selector = selector.getFila() * 8 + selector.getColumna();
	int num_casillas_validas = 0;
	for (int i = 0; i < piezas.getNum(); i++) {

		if (piezas.getPieza(i).getCasilla() == casilla_selector) {

			if ((piezas.getPiezap(i) != nullptr)) {
				
				Pieza* p_turno = piezas.getPiezap(i);
				bool mov_val;
				p_turno->movimientovalido(selector.getCasilla(), casilla_selector, mov_val);
				for (int destino = 0; destino < 64; destino++){
					if ((mov_val == TRUE) && (Interaccion::pieza_saltada(piezas, casilla_selector, destino) == FALSE))
						num_casillas_validas++;
					Punto::dibuja_punto(getCoord(destino));
				}
				//vcasillas_validas = new int[num_casillas_validas];
				/*for (int destino = 0; destino < 64; destino++) {
					for (int j = 0; j < num_casillas_validas;j++) {
						if ((mov_val == TRUE) && (Interaccion::pieza_saltada(piezas, casilla_selector, destino) == FALSE))
							//vcasillas_validas[j] = casilla_selector;
							Punto::dibuja_punto(0.908,0.91);
					}
				}*/
			}
		}
	}
}

