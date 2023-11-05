#pragma once
#include "masterheader.h"

class Ticket {
private:


    // Private member to store the unique ID of the ticket.
    int id;
    // Private member to store a pointer to the associated event.
    Event event;
    // Private member to store a pointer to the associated location.
    Location location;
    // Private member to store the type of the ticket.
    std::string ticketType;


    // Static counter for generating unique IDs
    static int uniqueIDCounter;// Static member to keep track of the next unique ID.

};