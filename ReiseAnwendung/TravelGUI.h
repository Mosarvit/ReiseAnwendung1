#ifndef TRAVEL_GUI
#define TRAVEL_GUI

#include "TravelNetwork.h"
#include "Booking.h"

class TravelGUI
{

public:

    // TravelNetwork wird als Referenz in der Klasse gespeichert, damit sie damit arbeiten kann.
    TravelGUI(TravelNetwork& rNetwork) : m_rNetwork(rNetwork) { }

    // zeigt ein Hauptmenü an.
    // Rückgabewert: der vom Nutzer gewählte Menüpunkt
    int showMenu();

    // Nutzerinteraktion zum Buchen eines Fluges
    // Rückgabewert: 'true', wenn die vom Nutzer gewählte Route gebucht werden soll, sonst 'false'
    bool flightBooking();

    // Gibt eine Liste aller gebuchten Reisen aus.
    void showBookingList();


private:

    Node* readCity(); // Helper Funktion, um eine Stadt einzulesen.

    TravelNetwork& m_rNetwork;

    std::list<Booking> m_bookings;

};


/*
 * Im Idealfall wirft die Anwendung im Fehlerfall eine Exception.
 */
class TravelGuiException
{

public:

    TravelGuiException(const std::string& msg) : m_msg(msg) {}

    std::string getError() const { return m_msg; }


private:

    std::string m_msg;

};

#endif