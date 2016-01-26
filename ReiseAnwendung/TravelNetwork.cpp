#include "TravelNetwork.h"
#include "FlightRoute.h"
#include "BusRoute.h"


void TravelNetwork::addFlightRoute(Node& rCity1, Node& rCity2, double dist)
{
    addEdge(new FlightRoute(rCity1, rCity2, dist));
    addEdge(new FlightRoute(rCity2, rCity1, dist));
}


void TravelNetwork::addBusRoute(Node& rCity1, Node& rCity2, double dist)
{
    addEdge(new BusRoute(rCity1, rCity2, dist));
    addEdge(new BusRoute(rCity2, rCity1, dist));
}


Node* TravelNetwork::getNodeById(const std::string& rNodeId)
{
    for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++) {
        if ((*it)->getID() == rNodeId)
            return *it;
    }
    return NULL;
}
