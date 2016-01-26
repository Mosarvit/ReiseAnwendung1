#ifndef BOOKING_H
#define BOOKING_H

#include "Node.h"
#include <string>

/*
 * Ein Struct zur Speicherung einer Buchung.
 */
struct Booking
{
    Node* m_pStart;
    Node* m_pDst;
    std::string m_firstname, m_lastname;
    std::string m_address1, m_address2;
    double m_price;
};


#endif