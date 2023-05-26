#include "Interaccion.h"
#include<math.h>
#include<iostream>
#include"Peon.h"
#include "ETSIDI.h"

Interaccion::Interaccion() {
	accion = FALSE;
}

void Interaccion::corona(Selector selector, ListaPiezas& piezas,int index)
{
	index_peon = index;
	std::cout << "Estoy en corona\n";
		int casilla_selector = selector.getFila() * 8 + selector.getColumna();
		if (selector.getCasilla() == 27)//Alfil
		{
			Alfil* aux = new Alfil(piezas.getPiezap(index)->getPos(), piezas.getPiezap(index)->getColor(), piezas.getPiezap(index)->getCasilla());
			piezas.agregar(aux);
			corona_peon = FALSE;
			piezas.eliminar(index);
		}

		if (selector.getCasilla() == 28)//Caballo
		{
			Caballo* aux = new Caballo(piezas.getPiezap(index)->getPos(), piezas.getPiezap(index)->getColor(), piezas.getPiezap(index)->getCasilla());
			piezas.agregar(aux);
			corona_peon = FALSE;
			piezas.eliminar(index);
		}

		if (selector.getCasilla() == 35)//Torre
		{
			Torre* aux = new Torre(piezas.getPiezap(index)->getPos(), piezas.getPiezap(index)->getColor(), piezas.getPiezap(index)->getCasilla());
			piezas.agregar(aux);
			corona_peon = FALSE;
			piezas.eliminar(index);
		}

		if (selector.getCasilla() == 36)//Reina
		{
			Reina* aux = new Reina(piezas.getPiezap(index)->getPos(), piezas.getPiezap(index)->getColor(), piezas.getPiezap(index)->getCasilla());
			piezas.agregar(aux);
			corona_peon = FALSE;
			piezas.eliminar(index);
		}
}

void Interaccion::mover_pieza(Selector selector, ListaPiezas &piezas)
{
	Coordenada destino = { 1 + ((-1.0) * selector.getColumna() / 4), 0.99 - 1.0 * selector.getFila() / 4 };
	int casilla_selector=selector.getFila()*8+selector.getColumna();

	bool pieza_amiga=FALSE;
	bool pieza_enemiga = FALSE;
	int index_enemiga;
	bool jaque_a_blanco = FALSE;
	bool jaque_a_negro = FALSE;
	bool enroque = FALSE;
	Pieza* torre_de_enroque;
	Coordenada destino_torre;
	int casilla_torre_enroque;
	
	for (int i = 0; i < piezas.getNum(); i++) {
		if(piezas.getPiezap(i)->getCasilla() ==selector.getCasilla()) {
			if ((piezas.getPiezap(i) != nullptr)) {
				Pieza* p_turno= piezas.getPiezap(i);
				bool mov_val;
				
				for (int j = 0; j < piezas.getNum(); j++) {
					if ((piezas.getPiezap(j)->getCasilla() == casilla_selector)) {
						if (piezas.getPiezap(j)->getColor() == p_turno->getColor()) {
							pieza_amiga = TRUE;
						}

						if((piezas.getPiezap(j)->getColor() != p_turno->getColor())&&(casilla_selector!=p_turno->getCasilla())) {
							pieza_enemiga = TRUE;
							if (piezas.getPiezap(j)->getTipo() == 4) {
								p_turno->setPieza_enemiga_pieza(TRUE);
							}
							index_enemiga = j;
						}
						
					}
				}
				
				p_turno->movimientovalido(selector.getCasilla(), casilla_selector, mov_val);

				if ((piezas.getPiezap(i)->getTipo()==5)&&(piezas.getPiezap(i)->getPieza_movida() ==0)) {
					for (int k = 0; k < piezas.getNum(); k++) {
						if ((piezas.getPiezap(k)->getTipo() == 6)
							&& (piezas.getPiezap(i)->getColor()== piezas.getPiezap(k)->getColor())
							&&(piezas.getPiezap(k)->getPieza_movida() == 0)
							) 
						{
							if (
								(casilla_selector==6)&&(piezas.getPiezap(k)->getCasilla() == 7)
								||
								(casilla_selector == 2) && (piezas.getPiezap(k)->getCasilla() == 0)
								||
								(casilla_selector == 58) && (piezas.getPiezap(k)->getCasilla() == 56)
								||
								(casilla_selector == 62) && (piezas.getPiezap(k)->getCasilla() == 63)
								) 
							{
								if (casilla_selector - piezas.getPiezap(i)->getCasilla()>0) {
									int suma = 0;
									for (int z = piezas.getPiezap(i)->getCasilla(); z < casilla_selector; z++) {
										bool jaque=FALSE;
										jaque=jaque_propio(piezas, z, z+1, p_turno, pieza_enemiga);
										if (jaque==1) {
											suma++;
										}
									}
									if (suma == 0) {
										mov_val = TRUE;
										torre_de_enroque = piezas.getPiezap(k);
										enroque = TRUE;
										if(p_turno->getColor() == 0) {
											casilla_torre_enroque = 5;
											destino_torre = { (float)(1 + ((-1.0) * (casilla_torre_enroque % 8) / 4)),(float)( 1 - 1.0 * (casilla_torre_enroque - casilla_torre_enroque % 8) / 4)};
										}
										else {
											casilla_torre_enroque = 61;
											destino_torre = { (float)(1 + ((-1.0) * (casilla_torre_enroque % 8) / 4)),(float)(1 - 1.0 * (casilla_torre_enroque - casilla_torre_enroque % 8) / 4) };
										}
									}
									else {
										mov_val = FALSE;
									}
								}
								else {
									int suma = 0;
									for (int z = piezas.getPiezap(i)->getCasilla(); z > casilla_selector; z--) {
										bool jaque = FALSE;
										jaque = jaque_propio(piezas, z, z - 1, p_turno, pieza_enemiga);
										if (jaque == 1) {
											suma++;
										}
									}
									if (suma == 0) {
										mov_val = TRUE;
										torre_de_enroque = piezas.getPiezap(k);
										enroque = TRUE;
										if (p_turno->getColor() == 0) {
											casilla_torre_enroque = 3;
											destino_torre = { (float)(1 + ((-1.0) * (casilla_torre_enroque % 8) / 4)),(float)(1 - 1.0 * (casilla_torre_enroque - casilla_torre_enroque % 8) / 4) };
										}
										else {
											casilla_torre_enroque = 59;
											destino_torre = { (float)(1 + ((-1.0) * (casilla_torre_enroque % 8) / 4)),(float)(1 - 1.0 * (casilla_torre_enroque - casilla_torre_enroque % 8) / 4) };
										}
									}
									else {
										mov_val = FALSE;
									}
								}
							}
						}
					}
				}
				if ((mov_val)&&(pieza_amiga==FALSE)&&(pieza_saltada(piezas,p_turno->getCasilla(), casilla_selector) == FALSE)) {

					if ((turno % 2 == 0) && (p_turno->getColor() == 0)) {
						jaque_a_blanco = jaque_propio(piezas, p_turno->getCasilla(), casilla_selector, p_turno, pieza_enemiga);
						if (jaque_a_blanco == 0) {
							if (enroque == TRUE) {
								p_turno->mueve(destino);
								p_turno->setCasilla(casilla_selector);
								torre_de_enroque->mueve(destino_torre);
								torre_de_enroque->setCasilla(casilla_torre_enroque);
							}
							else {
								p_turno->mueve(destino);
								p_turno->setCasilla(casilla_selector);
								if ((p_turno->getTipo() == 4) || (p_turno->getTipo() == 5) || (p_turno->getTipo() == 6)) {
									p_turno->setPieza_movida();
								}
								if ((p_turno->getTipo() == 4)&&(casilla_selector>55)&&(p_turno->getColor()==0))
								{
									corona(selector,piezas,i);
									setCorona();
								}
								if (pieza_enemiga == TRUE) {
									piezas.eliminar(index_enemiga);

								}
								jaque_a_negro = jaque_a_enemigo(piezas, p_turno->getCasilla(), casilla_selector, p_turno);
								turno++;
								jaque_mate(piezas, 1, pieza_enemiga);
							}
						}
					}
					if ((turno % 2 != 0) && (p_turno->getColor() != 0)) {
						jaque_a_negro = jaque_propio(piezas, p_turno->getCasilla(), casilla_selector, p_turno, pieza_enemiga);
						
						if (jaque_a_negro == 0) {
							if (enroque == TRUE) {
								p_turno->mueve(destino);
								p_turno->setCasilla(casilla_selector);
								torre_de_enroque->mueve(destino_torre);
								torre_de_enroque->setCasilla(casilla_torre_enroque);
							}
							else {
								p_turno->mueve(destino);
								p_turno->setCasilla(casilla_selector);
								if ((p_turno->getTipo() == 4) || (p_turno->getTipo() == 5) || (p_turno->getTipo() == 6)) {
									p_turno->setPieza_movida();
								}
								if ((p_turno->getTipo() == 4) && (casilla_selector < 8) && (p_turno->getColor() == 1))
								{
									std::cout << "Corona" << endl;
									corona(selector, piezas, i);
									setCorona();
								}
								if (pieza_enemiga == TRUE) {
									piezas.eliminar(index_enemiga);

								}
								jaque_a_blanco = jaque_a_enemigo(piezas, p_turno->getCasilla(), casilla_selector, p_turno);
								turno++;
								jaque_mate(piezas, 0, pieza_enemiga);
				
							}
						}
					}
				}
			}
		}
	}
	jaque_blanco = jaque_a_blanco;
	jaque_negro = jaque_a_negro;
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
				comprobacion = piezas.getPiezap(i);
				comprobacion->movimientovalido(comprobacion->getCasilla(), rey->getCasilla(), jaque);
				if (jaque == TRUE) {
					ETSIDI::play("sonidos/cuidao.wav");
					return jaque;
				}
			}
		}
	}

	saltar = pieza_saltada(piezas, p->getCasilla(), rey->getCasilla());
	if (saltar == FALSE) {
		p->movimientovalido(p->getCasilla(), rey->getCasilla(), jaque);

		if (jaque == TRUE) {
			ETSIDI::play("sonidos/cuidao.wav");
	
			return jaque;
		}
	}
	
	return FALSE;
}

bool Interaccion::jaque_propio(ListaPiezas& piezas, int origen, int destino, Pieza* p, bool pieza_enemiga) {
	bool jaque = FALSE;
	bool saltar = FALSE;
	bool mov_valido = FALSE;
	Pieza* rey, *comprobacion;
	int piezas_amigas[15]{};
	bool mov_rey = FALSE;

	int n = 0;
	for (int i = 0; i < piezas.getNum(); i++) {
		int pieza_comida = 100;
		if ((piezas.getPieza(i).getTipo() == 5) && (p->getColor() == piezas.getPieza(i).getColor())) {
			rey = piezas.getPiezap(i);
		}
	}

	for (int i = 0; i < piezas.getNum(); i++) {
		if ((piezas.getPiezap(i)->getColor()==rey->getColor())&&(piezas.getPiezap(i)!=rey)) {
			piezas_amigas[n] = piezas.getPiezap(i)->getCasilla();
			n++;
			//std::cout << "piezas_amigas: " << piezas_amigas[n-1] << endl;
		}
	}

	if (p == rey) {
		rey->movimientovalido(origen, destino, mov_rey);
		std::cout << "mov_rey: " << mov_rey << endl;
		if ((p == rey) && (mov_rey == TRUE)) {

			int n_ = n;
			std::cout << "destino rey: " << destino << endl;
			for (int k = 0; k < n; k++) {
				if (destino == piezas_amigas[k]) {
					n_--;
					std::cout << n_ << "   n: " << n << endl;
				}
			}
			if ((n == n_)) {
				saltar = pieza_saltada(piezas, origen, destino);
				p->setCasilla(destino);
			}
			else {
				return TRUE;
			}
		}
	}
	else {
		saltar = pieza_saltada(piezas, origen, destino);
		p->setCasilla(destino);
	}

	for (int i = 0; i < piezas.getNum(); i++) {
		int pieza_comida=100;//valor que ninguna pieza tendra
		if ((pieza_enemiga == 1)&&(piezas.getPieza(i).getCasilla()==destino)) {
			pieza_comida=i;
		}
		if ((i!=pieza_comida)&&(piezas.getPieza(i).getColor() != rey->getColor()) && (piezas.getPiezap(i) != p)) {
			
			comprobacion = piezas.getPiezap(i);
			comprobacion->movimientovalido(comprobacion->getCasilla(), rey->getCasilla(), mov_valido);
			if (mov_valido == 1) {
				saltar = pieza_saltada(piezas, piezas.getPieza(i).getCasilla(), rey->getCasilla());
				if (saltar == FALSE) {
					p->setCasilla(origen);
					ETSIDI::play("sonidos/cuidao.wav");
					return TRUE;
				}
			}
		}
		
	}


	p->setCasilla(origen);
	return FALSE;
}

void Interaccion::jaque_mate(ListaPiezas& piezas, bool color, bool enemiga) {
	bool nojaque = FALSE;
	bool saltar = FALSE; 
	bool saltar_propio = FALSE;
	bool mov_valido = FALSE;
	int nofin = 0;
	Pieza* rey, * comprobacion;
	for (int i = 0; i < piezas.getNum(); i++) {
		if ((piezas.getPieza(i).getTipo() == 5) && (color == piezas.getPieza(i).getColor())) {
			rey = piezas.getPiezap(i);
		}
	}
	
	for (int i = 0; i < piezas.getNum(); i++) {
		if (piezas.getPiezap(i)->getColor() ==color ) {
			//std::cout << "Color: " << color << endl;
			for (int j = 0; j < 64; j++) {
				piezas.getPiezap(i)->movimientovalido(piezas.getPiezap(i)->getCasilla(), j, mov_valido);
				if (mov_valido==TRUE) {

					if ((pieza_saltada(piezas, piezas.getPiezap(i)->getCasilla(),j)==FALSE)
						&&
						(jaque_propio(piezas, piezas.getPiezap(i)->getCasilla(), j, piezas.getPiezap(i), enemiga) == FALSE)) {
						nofin++;
					}
				}
			}
		}
	}

	std::cout << "nofin: " << nofin << endl;
	if (nofin == 0) {
		jaque_mate_partida = TRUE;
		ETSIDI::play("sonidos/gameover.wav");
		if (color==0) {
			std::cout << "Jaque mate gana negro\n";
			
		}
		if (color == 1) {
			std::cout << "Jaque mate gana blanco\n";
			
		}
		piezas.eliminarContenido();
	}
}
