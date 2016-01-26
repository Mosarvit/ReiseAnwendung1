#ifndef FLIGHT_ROUTE
#define FLIGHT_ROUTE

#include "Edge.h"

class FlightRoute : public Edge
{

public:

    FlightRoute(Node& rSrc, Node& rDst, double distance) : Edge(rSrc, rDst), m_distance(distance) { }

    // Kantengewicht = Preis (80€ + 10ct / km)
    virtual double getWeight() { return 80.0 + 0.10 * m_distance; }

    /*
    *   Zeit in Stunden = (700km/h) / strecke ==> mal 60 = Minuten
    *   nach 'int' casten, um Nachkommastellen zu eliminieren
    */
    int getMinutes() { return static_cast<int>((m_distance / 700.0) * 60); }

    double getPrice()  { return getWeight(); }

private:

    double m_distance;

};

#endif