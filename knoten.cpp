#include <vector>
#include "knoten.h"
#pragma once


Knoten::Knoten() {}
Knoten::Knoten(int id) {
	this->id = id;
}
int Knoten::gebeKnotenIDzurueck() {
	return this->id;
}
void Knoten::fuegeNachbarnDesKnotenhinzu(Knoten &uebergabeNachbarKnoten) {
	this->nachbarnDesKnoten.push_back(uebergabeNachbarKnoten.gebeKnotenIDzurueck()); 	
}
std::vector<int> Knoten::gebeAlleNachbarndesKnotenzurueck() {
	return this->nachbarnDesKnoten;
	//unordered_map<int, Kante>::iterator temp = kantenliste.find(2); //speichert *alle* Nachbarn in neuer Knotenliste
	//nachbarIDs.push_back(temp->second.gebeEndknotenIDzurueck());
	//cout << temp->second.gebeEndknotenIDzurueck() << endl;
}
