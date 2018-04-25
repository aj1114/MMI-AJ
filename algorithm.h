#pragma once
#include "graphstruktur.h"
#include <queue>

class algorithm {
public:
	algorithm();
	int breitensuche_iterativ(Graph &eingelesenerGraph);

	int starte_tiefensuche_rekursiv(Graph &eingelesenerGraph);
	void tiefensuche_rekursiv(Graph &eingelesenerGraph, Knoten &uebergabeKnoten, vector<bool> &besuchte_knoten);

private:
};