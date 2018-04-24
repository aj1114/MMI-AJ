#include "kanten.h"
#pragma once

Kante::Kante(){}
Kante::Kante(Knoten startknotenDerKante, Knoten endknotenDerKante) {
	this->startknotenDerKante = Knoten(startknotenDerKante.gebeKnotenIDzurueck());
	this->endknotenDerKante = Knoten(endknotenDerKante.gebeKnotenIDzurueck());
}
int Kante::gebeStartknotenIDzurueck() {
	return this->startknotenDerKante.gebeKnotenIDzurueck();
}
int Kante::gebeEndknotenIDzurueck() {
	return this->endknotenDerKante.gebeKnotenIDzurueck();
}
Knoten Kante::gebeStartknotenzurueck() {
	return this->startknotenDerKante;
}
Knoten Kante::gebeEndknotenzurueck() {
	return this->endknotenDerKante;
}


