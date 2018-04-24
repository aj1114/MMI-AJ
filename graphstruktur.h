#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include "knoten.h"
#include "kanten.h"
using namespace std;

class Graph {
public:
	Graph();
	~Graph();
	//Graph(Adjazenzliste initialAdjList);
	Graph dateieinlesen(string pfad_zu_datei, Graph &eingelesenerGraph);
	void setzeAnzahlKnoten_erstelleleereListe(int knotenanzahl); ///am Anfang bekommt Inhalt aus erster Zeile der txt-Datei
	int ausgabeAnzahlKnoten();
	int ausgabeAnzahlKanten();
	
	bool pruefeObGraphGerichtet();
	void setzeGraphgerichtet(bool gerichtetodernicht);

	void fuegeKnotenhinzu(int uebergabeneuerknotenID);
	bool entferneKnoten(Knoten uebergabeknoten); //Rueckgabewert = false falls Knoten nicht existiert
	void fuegeKantehinzu(Knoten &uebergabequellknoten, Knoten &uebergabezielknoten);
	bool entferneKante(Knoten uebergabequellknoten, Knoten uebergabezielknoten); //Rueckgabewert = 0 falls Knoten nicht existiert
	bool ueberpruefeObKanteVorhanden(Knoten &uebergabequellknoten, Knoten &uebergabezielknoten);
	bool ueberpruefeObKnotenVorhanden(Knoten &uebergabeknoten);
	
	//unordered_map<int, Kante> gebeNachbarKnotenZurueck(Knoten uebergabequellknoten);
	int gebeNaechsteUnbesuchteKnotenIDzurueck(vector<bool> &besuchte_knoten);
	Knoten gebeKnotenzurueck(int uebergabeKnotenID);

private:
	bool gerichtet;

	/*Complexity von unordered_map
		1-4) Average case: O(1), worst case O(size())
		5-6) Average case: O(N), where N is the number of elements to insert. Worse case: O(N*size()+N)
		7-8) Average case: O(1), worst case O(size())*/
	unordered_map<int, Knoten> knotenliste;			
	unordered_map<int, Kante> kantenliste;		///int ist hier die ID vom Startknoten der Kante -> wird also quasi doppelt gespeichert! (in klasse Kante ebenfalls)	 
};


