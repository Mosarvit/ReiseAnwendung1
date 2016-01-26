#ifndef BUS_ROUTE
#define BUS_ROUTE

#include "Edge.h"

class BusRoute : public Edge
{

public:

    BusRoute(Node& rSrc, Node& rDst, double distance) : Edge(rSrc, rDst), m_distance(distance) { }

    // Kantengewicht = Preis (18ct / km)
    virtual double getWeight() { return 0.18 * m_distance; }

    /*
    *   Zeit in Stunden = (700km/h) / strecke ==> mal 60 = Minuten
    *   nach 'int' casten, um Nachkommastellen zu eliminieren
    */
    int getMinutes() { return static_cast<int>((m_distance / 75) * 60); }

    double getPrice()  { return getWeight(); }

private:

    double m_distance;

};


#endif