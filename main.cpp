#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <algorithm>    // For std::remove()
using namespace std;
#include "graphstruktur.h"
#include "kanten.h"
#include "knoten.h"
#include "algorithm.h"
string pfad_zu_datei = "C:\\Users\\janster\\sciebo\\Studium_Semester_8_MA2\\MMI\\visualstudio\\graphen\\";


int main(){
	Graph eingelesenerGraph;	 //soll in allen Funktionen verf�gbar sein
	eingelesenerGraph.setzeGraphgerichtet(false);
	eingelesenerGraph = eingelesenerGraph.dateieinlesen(pfad_zu_datei, eingelesenerGraph);
	cout << "Knoten hinzugefuegt: " << eingelesenerGraph.ausgabeAnzahlKnoten() << endl;
	cout << "Kanten hinzugefuegt: " << eingelesenerGraph.ausgabeAnzahlKanten()/2 << endl;
	cout << endl;
	
	cout << "ZsmKomp mit it_breitensuche: " << algorithm().breitensuche_iterativ(eingelesenerGraph) << endl;
	cout << "ZsmKomp mit rek_tiefensuche: " << algorithm().starte_tiefensuche_rekursiv(eingelesenerGraph) << endl;
	
	system("pause");
	return 0;
}


