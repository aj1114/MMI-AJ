#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include "graphstruktur.h"
#include "algorithm.h"
#include <unordered_map>
using namespace std;
#pragma once;
// Aufgabe 1:	Breitensuche(iterativ) und Tiefensuche
//				(rekursiv) zur Bestimmung der Anzahl
//				der Zusammenhangskomponenten

algorithm::algorithm() {}

/*breitensuche_iterativ(start_node, goal_node) { //struktur
	for (all nodes i) visited[i] = false; // anfangs sind keine Knoten besucht
	queue.push(start_node);              // mit Start-Knoten beginnen
	visited[start_node] = true;
	while (!queue.empty()) {            // solange queue nicht leer ist
		node = queue.pop();                 // erstes Element von der queue nehmen
		if (node == goal_node) {
			return true;                       // testen, ob Ziel-Knoten gefunden
		}
		foreach(child in expand(node)) {    // alle Nachfolge-Knoten, …
			if (visited[child] == false) {      // … die noch nicht besucht wurden …
				queue.push(child);                // … zur queue hinzufügen…
				visited[child] = true;            // … und als bereits gesehen markieren
			}
		}
	}
	return false;                        // Knoten kann nicht erreicht werden
}
*/
int algorithm::breitensuche_iterativ(Graph &eingelesenerGraph) { //Rueckgabewert == Zusammenhangskomponenten - https://de.wikipedia.org/wiki/Breitensuche#Algorithmus_(formal)
	int anzahl_knoten_im_uebergebeben_graph = eingelesenerGraph.ausgabeAnzahlKnoten();
	int zusammenhangskomponenten = 0;
	vector<bool> besuchte_knoten;
	queue<Knoten> queue;
	for (int i = 0; i < eingelesenerGraph.ausgabeAnzahlKnoten(); i++) { //anfangs sind keine Knoten besucht - vektor der Größe erstellen
		besuchte_knoten.push_back(i);
		besuchte_knoten[i] = false;
	}
	Knoten startKnoten;
	Knoten tempKnoten;
	int startKnotenID = eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten); // Rueckgabewert -1 wenn alle besucht sind!! //fange mit Knoten[0] an
	int naechsterNachbar;
	vector<int> NachbarnDesKnotens;
	while (startKnotenID != -1) {
		startKnoten = eingelesenerGraph.gebeKnotenzurueck(startKnotenID);
		NachbarnDesKnotens = startKnoten.gebeAlleNachbarndesKnotenzurueck();
		queue.push(startKnoten); //ersten Knoten auf die Queue + "als besucht" setzen
		besuchte_knoten[startKnotenID] = true;

		while (!queue.empty()) {            // solange queue nicht leer ist
			if (eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten) == -1) exit; //wenn alle Knoten besucht, breche ab
			tempKnoten = queue.front();	// erstes Element zwischenspeichern
			queue.pop();				// erstes Element von der queue nehmen

			NachbarnDesKnotens = tempKnoten.gebeAlleNachbarndesKnotenzurueck();

			for (int i = 0; i < NachbarnDesKnotens.size(); i++) { //fuer alle nachfolgenden Knoten
				naechsterNachbar = NachbarnDesKnotens[i];
				//cout << "naechster Nachbar: " << naechsterNachbar ;
				if (besuchte_knoten[naechsterNachbar] == false) { //falls diese noch nicht besucht wurden
					queue.push(eingelesenerGraph.gebeKnotenzurueck(naechsterNachbar));
					//cout << "noch nicht besucht daher pushe: " << naechsterNachbar << endl;
					besuchte_knoten[naechsterNachbar] = true;
				}
			}
		}
		zusammenhangskomponenten++;
		startKnotenID = eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten); // Rueckgabewert -1 wenn alle besucht sind!!
		//cout << "naechster unbesuchter Knoten: " << startKnotenID << endl;
	}
	return zusammenhangskomponenten;
}


int algorithm::starte_tiefensuche_rekursiv(Graph &eingelesenerGraph) { //Rueckgabewert == Zusammenhangskomponenten
	int anzahl_knoten_im_uebergebeben_graph = eingelesenerGraph.ausgabeAnzahlKnoten();
	int zusammenhangskomponenten = 0;
	vector<bool> besuchte_knoten;
	for (int i = 0; i < eingelesenerGraph.ausgabeAnzahlKnoten(); i++) { //anfangs sind keine Knoten besucht - vektor der Größe erstellen
		besuchte_knoten.push_back(i);
		besuchte_knoten[i] = false;
	}
	int startKnotenID = eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten); // Rueckgabewert -1 wenn alle besucht sind!! //fange mit Knoten[0] an
	Knoten startKnoten;
	int counter = 0;
		
	while (startKnotenID != -1) {
		startKnoten = eingelesenerGraph.gebeKnotenzurueck(startKnotenID);
		tiefensuche_rekursiv(eingelesenerGraph, startKnoten, besuchte_knoten);
		zusammenhangskomponenten++;
		startKnotenID = eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten); // Rueckgabewert -1 wenn alle besucht sind!!
	}
	return zusammenhangskomponenten;
}

void algorithm::tiefensuche_rekursiv(Graph &eingelesenerGraph, Knoten &uebergabeKnoten, vector<bool> &besuchte_knoten) {
	besuchte_knoten[uebergabeKnoten.gebeKnotenIDzurueck()] = true; // wenn Knoten bereits besucht
	//b[x] = ++counter;
	int naechsterNachbar;
	Knoten naechsterKnoten;
	vector<int> NachbarnDesKnotens = uebergabeKnoten.gebeAlleNachbarndesKnotenzurueck();
	for (int i = 0; i < NachbarnDesKnotens.size(); i++) {
		naechsterNachbar = NachbarnDesKnotens[i];
		naechsterKnoten = eingelesenerGraph.gebeKnotenzurueck(naechsterNachbar);
		if (besuchte_knoten[naechsterNachbar] == false) {
			tiefensuche_rekursiv(eingelesenerGraph, naechsterKnoten, besuchte_knoten);
		}
	}
}
