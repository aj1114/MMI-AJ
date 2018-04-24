#include <iostream>
#include "knoten.h"
#pragma once

class Kante {
private:
	Knoten startknotenDerKante;
	Knoten endknotenDerKante;
	int gewicht;

	//evt vecor 

public:
	Kante();
	Kante(Knoten startknotenDerKante, Knoten endknotenDerKante);
	//Kante(Knoten quellknoten, Knoten endknotenDerKante, int gewicht);
	int gebeStartknotenIDzurueck();
	int gebeEndknotenIDzurueck();
	Knoten gebeStartknotenzurueck();
	Knoten gebeEndknotenzurueck();

};
