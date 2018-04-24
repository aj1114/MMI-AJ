#include <vector>
#include <iostream>
#include <iomanip>
#include "graphstruktur.h"
#include "algorithm.h"
#include <unordered_map>
using namespace std;
#pragma once;
// Aufgabe 1:	Breitensuche(iterativ) und Tiefensuche
//				(rekursiv) zur Bestimmung der Anzahl
//				der Zusammenhangskomponenten


algorithm::algorithm(){}


/*breitensuche_iterativ(start_node, goal_node) {
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



int algorithm::breitensuche_iterativ(Graph eingelesenerGraph) { //Rueckgabewert == Zusammenhangskomponenten - https://de.wikipedia.org/wiki/Breitensuche#Algorithmus_(formal)
	int anzahl_knoten_im_uebergebeben_graph = eingelesenerGraph.ausgabeAnzahlKnoten();
	vector<bool> besuchte_knoten;
	for (int i = 0; i < eingelesenerGraph.ausgabeAnzahlKnoten(); i++) { //anfangs sind keine Knoten besucht - vektor der Größe erstellen
		besuchte_knoten.push_back(i);
		besuchte_knoten[i] = false;
	}
	cout << "anzahl nicht besuchte Knoten: " << besuchte_knoten.size() << endl;


	int unbesuchteKnotenID = eingelesenerGraph.gebeNaechsteUnbesuchteKnotenIDzurueck(besuchte_knoten); // Rueckgabewert -1 wenn alle besucht sind!!
	


	//std::vector<int> nachbarn = eingelesenerGraph->Kn

	cout << "erste unbesuchte ID: " << unbesuchteKnotenID << endl;

	//eingelesenerGraph.gebeAlleNachbarKnotenIDsZurueck(unbesuchteKnotenID);

	//Startknoten: der erste Knoten des Graphen
	/*for (auto it = kantenliste.begin(); it != kantenliste.end(); ++it)
	cout << " " << it->first << ":" << it->second;
	cout << endl;
	queue.push(Graph.g)
		Graph.
	*/
	return 1; 
}




/*
map<int, vector<int> > Algorithmen::getAdjlist(void) { //macht aus der Knotenliste iene Adjazentenliste
	int nodelistSize = V + E + 2; // Größe der Knotenliste
	int i = 2, j = 0;
	map<int, vector<int> > graph; // DS für die Adjazenzliste
	while (i < nodelistSize) { // Knoten verarbeiten
		int ag = nodelist[i]; // Knotenanzahl
		graph[j]; // damit der Knoten j in der Adjazenzliste angelegt wird
		for (int k = i + 1; k < i + ag + 1; k++) {
			int node = nodelist[k]; // Knoten
			graph[j].push_back(node); // Knoten zum Feld hinzufügen
		}
		i = i + ag + 1; // Index weitersetzen
		j++;
	}
	return graph;
};
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
vector<int> Algorithmen::iterativeBreadthSearch(map<int, vector<int> > adjlist, int startnode) {
	cout << "Starten der iterativen Breitensuche" << endl;
	vector<int> val;
	for (int i = 0; i < adjlist.size(); i++) {
		val.push_back(0);
	}
	id = 0;
	std::queue<int> nodeQueue;
	nodeQueue.push(startnode);
	while (!nodeQueue.empty()) {
		int node = nodeQueue.front();
		nodeQueue.pop();
		val[node] = ++id;
		cout << "BSI(" << node << ")" << endl;
		for (int i = 0; i < adjlist[node].size(); i++) {
			if (val[adjlist[node][i]] == 0) {
				if (val[adjlist[node][i]] == 0) {
					nodeQueue.push(adjlist[node][i]);
					val[adjlist[node][i]] = -1;
				}
			}
		}
	}
	cout << endl;
	return val;
};
*/