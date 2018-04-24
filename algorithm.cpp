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

algorithm::algorithm(){}

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


/*int algorithm::starte_tiefensuche_rekursiv(Graph &eingelesenerGraph) { //Rueckgabewert == Zusammenhangskomponenten - https://de.wikipedia.org/wiki/Breitensuche#Algorithmus_(formal)
	int anzahl_knoten_im_uebergebeben_graph = eingelesenerGraph.ausgabeAnzahlKnoten();
	int zusammenhangskomponenten = 0;
	vector<bool> besuchte_knoten;
	for (int i = 0; i < eingelesenerGraph.ausgabeAnzahlKnoten(); i++) { //anfangs sind keine Knoten besucht - vektor der Größe erstellen
		besuchte_knoten.push_back(i);
		besuchte_knoten[i] = false;
	}
	int startKnotenID = eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten); // Rueckgabewert -1 wenn alle besucht sind!! //fange mit Knoten[0] an
	Knoten startKnoten = eingelesenerGraph.gebeKnotenzurueck(startKnotenID);
	int counter = 0;
		
	
	while (startKnotenID != -1) {
		tiefensuche_rekursiv(startKnoten);
	}

	
	return zusammenhangskomponenten;
}

void algorithm::tiefensuche_rekursiv(Knoten &uebergabeKnoten) {
	// zu x existiert Weg aus Baumkanten
	besucht[x] = true; b[x] = ++counter;
	for (y in Nachbarn von x) {
		if (not besucht[y]) {
			dfs(y); // xy heißt Baum-Kante
		}
	}
}
*/


/*
vector<int> Algorithmen::startRecursiveDepthSearch(map<int, vector<int> > adjlist) {
	cout << "Starten der rekursiven Tiefensuche" << std::endl;
	vector<int> val;
	for (int i = 0; i < adjlist.size(); i++) {
		val.push_back(0);
	}
	id = 0;
	recursiveDepthSearch(adjlist, 0, val);
	cout << endl;
	return val;
};
void Algorithmen::recursiveDepthSearch(map<int, vector<int> > adjlist, int node, vector<int> &val) {
	cout << "TSR(" << node << ")" << endl;
	val[node] = ++id;								// Speichern der wievielte besuchte Knoten es ist
	for (int i = 0; i < adjlist[node].size(); i++) {	// Für alle Nachbarn
		if (val[adjliast[node][i]] == 0) {			// Prüfen ob sie noch nicht besucht wurden ( =0 )
			recursiveDepthSearch(adjlist, adjlist[node][i], val);
		}
	}
};
*/
