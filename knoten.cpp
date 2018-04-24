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
void Knoten::fuegeNachbarnDesKnotenhinzu(int uebergabeNachbarKnotenID) {
	//in Klasse Knoten definiert:	std::vector<int> nachbarnDesKnoten;
	this->nachbarnDesKnoten.push_back(uebergabeNachbarKnotenID); 	
	
	if (this->id == 0) {
		std::cout << "ID hinzugefuegt zu " << this->id << " : " << uebergabeNachbarKnotenID << std::endl;
		for (int i = 0; i < this->nachbarnDesKnoten.size(); i++) {
			std::cout << this->nachbarnDesKnoten[i] << " ,";
		}
		std::cout << std::endl;
	}
}
std::vector<int> Knoten::gebeAlleNachbarndesKnotenzurueck() {
	return this->nachbarnDesKnoten;
	//unordered_map<int, Kante>::iterator temp = kantenliste.find(2); //speichert *alle* Nachbarn in neuer Knotenliste
	//nachbarIDs.push_back(temp->second.gebeEndknotenIDzurueck());
	//cout << temp->second.gebeEndknotenIDzurueck() << endl;
}
