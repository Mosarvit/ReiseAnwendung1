#ifndef TRAVEL_NETWORK
#define TRAVEL_NETWORK

#include "Graph.h"


class TravelNetwork : public Graph
{

public:

    // kleine Hilfsfunktion, um eine bidirektionale Flugverbindung schneller einzutragen
    void addFlightRoute(Node& rCity1, Node& rCity2, double dist);

    // kleine Hilfsfunktion, um eine bidirektionale Busverbindung schneller einzutragen
    void addBusRoute(Node& rCity1, Node& rCity2, double dist);

    // Nodes anhand ihrer ID abfragen. (wird für die Nutzereingabe benötigt)
    Node* getNodeById(const std::string& rNodeId);


private:

    // Graph::addEdge wird private. 
    // Es soll 'von außen' nur noch addFlightRoute und addBusRoute verwendet werden.
    using Graph::addEdge; 

};


#endif