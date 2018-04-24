#pragma once
#include "graphstruktur.h"
#include <queue>

class algorithm {
public:
	algorithm();
	int breitensuche_iterativ(Graph &eingelesenerGraph);
	int starte_tiefensuche_rekursiv(Graph &eingelesenerGraph);
	void tiefensuche_rekursiv(Knoten &uebergabeKnoten);


private:

};