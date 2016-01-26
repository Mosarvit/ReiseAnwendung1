#include <iostream>

#include "TravelNetwork.h"
#include "TravelGUI.h"


int main()
{
    TravelNetwork routes;

    Node& rBerlin = routes.addNode(new Node("Berlin"));
    Node& rMadrid = routes.addNode(new Node("Madrid"));
    Node& rWien = routes.addNode(new Node("Wien"));
    Node& rBarcelona = routes.addNode(new Node("Barcelona"));
    Node& rLondon = routes.addNode(new Node("London"));
    Node& rNewYork = routes.addNode(new Node("NewYork"));

    routes.addFlightRoute(rBerlin, rMadrid, 1900);
    routes.addFlightRoute(rBerlin, rWien, 530);
    routes.addFlightRoute(rWien, rMadrid, 1800);
    routes.addFlightRoute(rMadrid, rBarcelona, 505);
    routes.addFlightRoute(rBerlin, rLondon, 930);
    routes.addFlightRoute(rLondon, rNewYork, 5600);

    routes.addBusRoute(rBerlin, rMadrid, 2300);
    routes.addBusRoute(rBerlin, rWien, 680);
    routes.addBusRoute(rWien, rMadrid, 2450);
    routes.addBusRoute(rMadrid, rBarcelona, 619);
    
    TravelGUI gui(routes);

    bool bRunning = true;

    // Endlosschleife, bis bRunning auf 'false' gesetzt wird
    while (bRunning)
    {
        int menuEntry = gui.showMenu();

        // Hinweis: Die Fallunterscheidung geht auch mit Switch-Case (siehe C-Programmierung)

        // Flug buchen
        if (menuEntry == 1) 
        {
            try {
                gui.flightBooking();
            }
            catch (const TravelGuiException& e) {
                std::cout << "Route konnte nicht gebucht werden!" << std::endl;
                std::cout << "Ursache: " << e.getError() << std::endl;
            }
        }
        // Liste aller Buchungen anzeigen
        else if (menuEntry == 2) 
        {
            gui.showBookingList();
        }
        // Schleife verlassen und Programm beenden
        else if (menuEntry == 3)
        {
            bRunning = false; 
        }
        // falsche Eingabe
        else 
        {
            std::cout << "Fehlerhafte Eingabe! Bitte wiederholen ..." << std::endl;
        }
    }

    return 0;
}