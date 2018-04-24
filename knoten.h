#include <iostream>
#include <iomanip>
#include <vector>
#pragma once

class Knoten {
private:
	int id;
	std::vector<int> nachbarnDesKnoten;

public:
	Knoten();
	Knoten(int id);
	int gebeKnotenIDzurueck();
	void fuegeNachbarnDesKnotenhinzu(Knoten &uebergabeNachbarKnoten);
	std::vector<int> gebeAlleNachbarndesKnotenzurueck();
};