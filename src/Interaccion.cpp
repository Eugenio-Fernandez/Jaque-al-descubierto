#include "Interaccion.h"
#include<math.h>
#include<iostream>
#include"Peon.h"

Interaccion::Interaccion() {
	accion = FALSE;
}

void Interaccion::mover_pieza(Selector selector, ListaPiezas &piezas)
{
	Coordenada destino = { 1 + ((-1.0) * selector.getColumna() / 4), 0.99 - 1.0 * selector.getFila() / 4 };
	int casilla_selector=selector.getFila()*8+selector.getColumna();
	std::cout << "Casilla selector: " << casilla_selector << "   " << selector.getFila() * 8 + selector.getColumna() << endl;
	//bool casilla_vacia=FALSE;
	bool pieza_amiga=FALSE;
	bool pieza_enemiga = FALSE;
	int index_enemiga;
	bool jaque_a_blanco = FALSE;
	bool jaque_a_negro = FALSE;
	
	for (int i = 0; i < piezas.getNum(); i++) {
		//std::cout << "hola" << endl;
		//std::cout << piezas.getPieza(i).getCasilla() << " , " << selector.getCasilla() << endl;
		if(piezas.getPieza(i).getCasilla() ==selector.getCasilla()) {
			//std::cout << "hola mundo\n";
			//std::cout <<  casilla_selector << endl;
			if ((piezas.getPiezap(i) != nullptr)) {
				Pieza* p_turno= piezas.getPiezap(i);
				bool mov_val;
				p_turno->movimientovalido(selector.getCasilla(), casilla_selector, mov_val);
				for (int j = 0; j < piezas.getNum(); j++) {
					if ((piezas.getPiezap(j)->getCasilla() == casilla_selector)&&(piezas.getPiezap(j)->getTipo()!=5)) {
						//casilla_vacia = TRUE;
						if (piezas.getPiezap(j)->getColor() == p_turno->getColor()) {
							pieza_amiga = TRUE;
						}

						if((piezas.getPiezap(j)->getColor() != p_turno->getColor())&&(casilla_selector!=p_turno->getCasilla())) {
							pieza_enemiga = TRUE;
							index_enemiga = j;
						}
						
					}
				}
				if ((mov_val)&&(pieza_amiga==FALSE)&&(pieza_saltada(piezas,p_turno->getCasilla(), casilla_selector) == FALSE)) {

					if ((turno % 2 == 0) && (p_turno->getColor() == 0)) {
						jaque_a_blanco = jaque_propio(piezas, p_turno->getCasilla(), casilla_selector, p_turno, pieza_enemiga);
						std::cout << "Jaque a blanco: " << jaque_a_blanco << endl;
						if (jaque_a_blanco == 0) {
							p_turno->mueve(destino);
							p_turno->setCasilla(casilla_selector);
							std::cout << "Casilla selector: " << casilla_selector << endl;
							if (pieza_enemiga == TRUE) {
								piezas.eliminar(index_enemiga);

							}
							jaque_a_negro = jaque_a_enemigo(piezas, p_turno->getCasilla(), casilla_selector, p_turno);
							std::cout << "Jaque a negro: " << jaque_a_negro << endl;
							turno++;
						}
					}
					
					if ((turno % 2 != 0) && (p_turno->getColor() != 0)) {
						jaque_a_negro = jaque_propio(piezas, p_turno->getCasilla(), casilla_selector, p_turno, pieza_enemiga);
						std::cout << "Jaque a negro: " << jaque_a_negro << endl;
						if (jaque_a_negro==0) {
							p_turno->mueve(destino);
							p_turno->setCasilla(casilla_selector);
							if (pieza_enemiga == TRUE) {
								piezas.eliminar(index_enemiga);

							}
							jaque_a_blanco = jaque_a_enemigo(piezas, p_turno->getCasilla(), casilla_selector, p_turno);
							std::cout << "Jaque a blanco: " << jaque_a_blanco << endl;
							turno++;
						}
					}
					//std::cout << piezas.getPieza(i).getPos().x << " , " << piezas.getPieza(i).getPos().y << endl;
				}
			}
		}
	}
}

void Interaccion::setAccion() {
	if (accion == TRUE) {
		accion = FALSE;
	}
	else {
		accion = TRUE;
	}
}

bool Interaccion::getAccion() {
	return accion;
}

bool Interaccion::pieza_saltada(ListaPiezas& piezas, int origen, int destino) {
	int dif;
	int mov=0;

	dif = destino - origen;

	if ((dif == 10) || ((dif == 6) && (abs(destino - origen) > 8)) || ((dif == -6) && (abs(destino - origen) > 8))
		|| (dif == -10) || (dif == 17) || (dif == 15) || (dif == -15) || (dif == -17)) {
		return FALSE;//el caballo puede saltar
	}

	if (dif != 1) {
		for (int i = 10; i >= 2; i--) {
			if (i != 0) {
				if (((dif % i) == 0)) {
					mov = i;
					break;
				}
			}
		}
	}
	if((dif==1)||(dif==-1)) {
		mov = 1;
	}
	if (dif * mov < 0) {
		mov = -mov;
	}
	//std::cout << "mov: " << mov << endl;

	if (mov != 0) {
		for (int i = 0; i < piezas.getNum(); i++) {
			for (int j = 1; j < (dif / mov); j++) {
				if (piezas.getPieza(i).getCasilla() == origen + mov * j) {
					return TRUE;
				}
			}
			if ((abs(mov) < 8) && ((origen % 8 + mov < 8)) && ((origen % 8 + mov >= 0))) {
				for (int j = 1; j < abs(mov); j++) {
					//std::cout << "origen + j: " << origen + j << endl;
					//std::cout << "origen - j: " << origen - j << endl;
					if (mov > 0) {
						if (piezas.getPieza(i).getCasilla() == origen + j) {
							return TRUE;
						}
					}
					else {
						if (piezas.getPieza(i).getCasilla() == origen - j) {
							return TRUE;
						}
					}
				}
			}
		}
	}
	return FALSE;
}


bool Interaccion::jaque_a_enemigo(ListaPiezas& piezas, int origen, int destino, Pieza *p) {
	bool jaque=FALSE;
	bool saltar = FALSE;
	Pieza* rey, *comprobacion;
	for (int i = 0; i < piezas.getNum(); i++) {
		if ((piezas.getPieza(i).getTipo() == 5)&&(p->getColor() != piezas.getPieza(i).getColor())) {
			rey = piezas.getPiezap(i);
		}
	}

	for (int i = 0; i < piezas.getNum();i++) {
		if ((piezas.getPieza(i).getColor() != rey->getColor()) && (piezas.getPiezap(i) != rey)&&(piezas.getPiezap(i)!=p)) {
			saltar = pieza_saltada(piezas, piezas.getPieza(i).getCasilla(), rey->getCasilla());
			if (saltar == FALSE) {
				//piezas.getPieza(i).movimientovalido(piezas.getPieza(i).getCasilla(),rey->getCasilla(),jaque);
				comprobacion = piezas.getPiezap(i);
				comprobacion->movimientovalido(piezas.getPieza(i).getCasilla(), rey->getCasilla(), jaque);
				if (jaque == TRUE) {
					std::cout << "JAQUE\n";
					return jaque;
				}
			}
		}
	}

	saltar = pieza_saltada(piezas, p->getCasilla(), rey->getCasilla());
	std::cout << "Casilla " << p->getCasilla() << "  Casilla rey " << rey->getCasilla() << "  saltar " << saltar << endl;
	if (saltar == FALSE) {
		p->movimientovalido(p->getCasilla(), rey->getCasilla(), jaque);
		std::cout << "holi\n";
		if (jaque == TRUE) {
			std::cout << "JAQUE\n";
			return jaque;
		}
	}
	
	return FALSE;
}

bool Interaccion::jaque_propio(ListaPiezas& piezas, int origen, int destino, Pieza* p, bool pieza_enemiga) {
	bool jaque = FALSE;
	bool saltar = FALSE;
	Pieza* rey, *comprobacion;
	for (int i = 0; i < piezas.getNum(); i++) {
		if ((piezas.getPieza(i).getTipo() == 5) && (p->getColor() == piezas.getPieza(i).getColor())) {
			rey = piezas.getPiezap(i);
		}
	}

	saltar = pieza_saltada(piezas, origen, destino);
	p->setCasilla(destino);

	for (int i = 0; i < piezas.getNum(); i++) {
		int pieza_comida=100;//valor que ninguna pieza tendra
		if ((pieza_enemiga == 1)&&(piezas.getPieza(i).getCasilla()==destino)) {
			pieza_comida=i;
		}
		if ((i!=pieza_comida)&&(piezas.getPieza(i).getColor() != rey->getColor()) && (piezas.getPiezap(i) != rey) && (piezas.getPiezap(i) != p)) {
			saltar = pieza_saltada(piezas, piezas.getPieza(i).getCasilla(), rey->getCasilla());
			if (saltar == FALSE) {
				//piezas.getPieza(i).movimientovalido(piezas.getPieza(i).getCasilla(), rey->getCasilla(), jaque);
				comprobacion = piezas.getPiezap(i);
				comprobacion->movimientovalido(piezas.getPieza(i).getCasilla(), rey->getCasilla(), jaque);
				if (jaque == TRUE) {

					std::cout << "JAQUE\n";
					p->setCasilla(origen);
					return jaque;
				}
			}
		}
	}

	return FALSE;
}