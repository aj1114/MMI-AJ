#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <algorithm>    // For std::remove()
#include "graphstruktur.h"
#include <unordered_map>
using namespace std;
#pragma once;

Graph::Graph(){}
Graph::~Graph(void){}
Graph Graph::dateieinlesen(string pfad_zu_datei, Graph &eingelesenerGraph) {
	string einleseformat;
	string dateiname;

	cout << "Bitte Dateinamen eingeben:  ";
	cin >> dateiname;
	pfad_zu_datei += dateiname;
	cout << "Einzulesende Datei: " << pfad_zu_datei << "\n";
	ifstream input(pfad_zu_datei);
	if (!input) { 		// Überprüfung ob Datei geoeffnet wurde oder existiert
		cerr << "Datei wurde nicht gefunden." << endl;
		exit;
	}
	string line; //zwischenspeicher Einzulesende Zeile
	int i = 0; //zaehler
	Knoten Startknoten;
	Knoten Zielknoten;
	int id_startknoten;
	int id_zielknoten;
	while (getline(input, line)) { //solange noch Inhalt bzw. naechste Zeile existiert
		if (i == 0) {
			eingelesenerGraph.setzeAnzahlKnoten_erstelleleereListe(stoi(line)); //string to int -> erste Zahl in Textdatei == Anzahl Knoten
		}
		i++; //sorgt dafuer, dass V nicht ueberschrieben wird + knoten nur 1x angelegt werden + jede Zeile durchlaufen wird
		if (i == 2) { //bei der zweiten Zeile ueberpruefen ob es sich um eine Liste oder eine Matrix handelt
			if (line.length() > 15) { //ab 15 Zeichen
				einleseformat = "matrix"; //wenn mehr als 5 Zeichen in der 2. Zeile == adj.matrix
				cout << "Matrix erkannt!\n";
			}
			else {
				einleseformat = "liste";
				cout << "Liste erkannt!\n";
			}
		}
		if (i > 1) { //ab der zweiten Zeile also (V auslassen)
			 ////////////////////////////////////ABSPEICHERN der Werte///////////////////////////	//input: string "line" 
			if (einleseformat == "liste") {															//Liste	- BSP: 0 6 //Leerzeichen oder Tab
				int tabzeichen = line.find("\t");
				int endzeichen = line.find("\n");
				id_startknoten = stoi(line.substr(0, tabzeichen));
				id_zielknoten = stoi(line.substr((tabzeichen +1), endzeichen));

				//cout << "Quellknoten: " << startknoten << " Zielknoten: " << zielknoten << "\n";
				//evt. hier Gewichtung mit einbauen falls mit eingelesen werden soll

				Startknoten= eingelesenerGraph.gebeKnotenzurueck(id_startknoten);
				Zielknoten = eingelesenerGraph.gebeKnotenzurueck(id_zielknoten);
			
				eingelesenerGraph.fuegeKantehinzu(Startknoten, Zielknoten);
				if (eingelesenerGraph.pruefeObGraphGerichtet() == false)
					eingelesenerGraph.fuegeKantehinzu(Zielknoten, Startknoten);		//Rueckrichtung
			}
			else { //Matrix - BSP: 0	0	0	0	0	0	1	0	0	1	0	0	0	1	0 
				   //aktuell werden Kanten in beide Richtungen angelegt, sodass bei einem gerichteten Grafen die Rückrichtungen wieder entfernt werden muessen
				id_startknoten = i - 2;  //beginnt ja ab 0
				Startknoten = eingelesenerGraph.gebeKnotenzurueck(id_startknoten);
				line.erase(std::remove(line.begin(), line.end(), '\t'), line.end()); // Tabs in Zeile entfernen

				for (int z = 0; z < line.length(); z++) { // in Zeile jedes Zeichen einzeln durchgehen
					if (line[z] == '1') {  //also eine Kante
						Zielknoten = eingelesenerGraph.gebeKnotenzurueck(z);
						eingelesenerGraph.fuegeKantehinzu(Startknoten, Zielknoten); // z==Zielknoten
					}
				}
			}
		}
	}//ende Zeilen durchgehen
	return eingelesenerGraph;
}
bool Graph::pruefeObGraphGerichtet() {
	return this->gerichtet;
}
void Graph::setzeGraphgerichtet(bool gerichtetodernicht) {
	this->gerichtet = gerichtetodernicht;
}
int Graph::ausgabeAnzahlKnoten() {
	return knotenliste.size();
}
void Graph::setzeAnzahlKnoten_erstelleleereListe(int knotenanzahl) {
	for (int i = 0; i < knotenanzahl; i++) {
		this->fuegeKnotenhinzu(i);
	}
}
int Graph::ausgabeAnzahlKanten() {
	return kantenliste.size();
}
bool Graph::ueberpruefeObKanteVorhanden(Knoten &uebergabequellknoten, Knoten &uebergabezielknoten) {
	unordered_map<int, Kante>::iterator temp = kantenliste.find(uebergabequellknoten.gebeKnotenIDzurueck()); //legt eine neue temp. map an mit allen Kanten die von Quellknoten aus abgehen
	if (temp == kantenliste.end()) { //wenn StartKnotenID nicht in der neuen Map gefunden wurde gibt es von dort logischerweise auch keine Kante.
		//cout << "vom Knoten " << quellknoten << "aus gibt es keine Kante!" << endl;
		return false;
	}
	else { //der Quellknoten befindet sich also in der MAP -> jetzt muss geprueft werden ob von dort ebenfalls eine Kante zum ZielKnoten fuehrt:
		if (temp->second.gebeEndknotenIDzurueck() == uebergabezielknoten.gebeKnotenIDzurueck()) { //also zweiter Eintrag ist der Zielknoten == dann existiert Kante
			//cout << "Kante existiert! Von: " << temp->first << " nach: " << temp->second << endl;
			return true;
		}
	}
	//cout << "Von Knoten " << temp->first << " gibt es keine Kante nach: " << zielknoten << endl;
	return false; //andernfalls gibt es zwar den quellknoten aber keine kante zum Zielknoten
}
bool Graph::ueberpruefeObKnotenVorhanden(Knoten &uebergabeknoten) {
	//unordered_map<int, int>::const_iterator temp = knotenliste.find(uebergabeknoten.gebeKnotenIDzurueck());
	
	if (knotenliste.find(uebergabeknoten.gebeKnotenIDzurueck()) == knotenliste.end()){
		//cout << "Knoten " << uebergabeknoten.gebeKnotenIDzurueck() << "nicht gefunden!" << endl;
		return false;
	}	
	else {
		//cout << "Knoten: " << uebergabeknoten.gebeKnotenIDzurueck()   << " existiert!" << endl;
		return true;
	}
}
void Graph::fuegeKantehinzu(Knoten &uebergabequellknoten, Knoten &uebergabezielknoten) {
	//Idee: hash aus KnotenID1 + "-" + KnotenID2 bilden:
	string id1_id2 = to_string(uebergabequellknoten.gebeKnotenIDzurueck()) + '-' + to_string(uebergabezielknoten.gebeKnotenIDzurueck());
	hash<string> hash_funktion;
	size_t id1_id2_hashed = hash_funktion(id1_id2); 
		
	//cout << " zu hashende ID: " << id1_id2 << " neuer hashwert: " << id1_id2_hashed << endl;
	Kante neueKante = Kante(uebergabequellknoten, uebergabezielknoten);
	kantenliste.insert({ id1_id2_hashed, neueKante });

	///Achtung: Hier Erweiterung einfuegen, falls Kantengewicht mit eingefuehrt wird!
	
	//neuen Nachbarn an den Nachbar-Vektor des Knotens hinzufuegen:
	knotenliste[uebergabequellknoten.gebeKnotenIDzurueck()].fuegeNachbarnDesKnotenhinzu(uebergabezielknoten);
}
void Graph::fuegeKnotenhinzu(int uebergabeneuerknotenID){
	Knoten neuerKnoten = Knoten(uebergabeneuerknotenID);
	if (ueberpruefeObKnotenVorhanden(neuerKnoten) == false) {
		knotenliste.insert({uebergabeneuerknotenID, neuerKnoten });
		//cout << "Neuen Knoten hinzugefuegt: " << uebergabeneuerknoten.gebeKnotenIDzurueck() << endl;
	}
}
bool Graph::entferneKnoten(Knoten alterknoten) {
	if (ueberpruefeObKnotenVorhanden(alterknoten)) {
		knotenliste.erase({ alterknoten.gebeKnotenIDzurueck() });
		cout << "Knoten gelöscht: " << alterknoten.gebeKnotenIDzurueck() << endl;
		return true;
		//erweitern da kanten ja auch geloescht werden muessen + graph umstrukturieren
	}
	else return false;
}
bool Graph::entferneKante(Knoten uebergabequellknoten, Knoten uebergabezielknoten) {
	if (ueberpruefeObKanteVorhanden(uebergabequellknoten, uebergabezielknoten)) {
	//	knotenliste.erase({ quellknoten);
	//	cout << "Knoten gelöscht: " << alterknoten << endl;
	//	return true;
	//erweitern da kanten ja auch geloescht werden muessen + graph umstrukturieren
		cout << "Achtung, Funktion entferneKante nicht vollstaendig!!" << endl;
	}
	return false;
}
int Graph::gebeNaechsteUnbesuchteKnotenIDzurueck(vector<bool> &besuchte_knoten) {
	for (int i = 0; i < besuchte_knoten.size(); i++){
		if (besuchte_knoten[i] == false) return i; //sobald nicht besuchter Knoten gefunden, gebe diesen zurueck
	}
	return -1; //wenn keine unbesuchten mehr vorhanden
}
Knoten Graph::gebeKnotenzurueck(int uebergabeKnotenID) {
	if (knotenliste.find(uebergabeKnotenID) == knotenliste.end()) {
		return NULL;
	}
	else return knotenliste[uebergabeKnotenID];
}


