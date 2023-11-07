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


public:

    Ticket() {//default constructor
        id = 0;
        event = {};
        location = {};
        ticketType = "";
        uniqueIDCounter = 0;
    }

    // Constructor: Initialize the Ticket object with provided values.
    Ticket(Event event, Location location, const std::string& ticketType) :
        event(event), location(location), ticketType(ticketType) {
        // Generate a unique ID for the ticket.
        id = generateUniqueID();
    }

    // Generate a unique ID
    static long long generateUniqueID() {//cautam intr un fisier idul ult bilet emis si vom returna valoarea +1
        //long long -> pt ca cea mai mare val este 2 la puterea 63 scazut cu 1
        // Increment and return the static counter to generate unique IDs.
        return ++uniqueIDCounter;
    }

    //ID accessor methods
    //getters - provide read access
    int getID() {
        return this->id;
    }

    //setters - provide write access
    void setID(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->id = value;
        }
        else {

            throw "Wrong value";

        }
    }

    //EVENT accessor methods
    //getters - provide read access
    Event getevent() {
        return this->event;
    }

    //setters - provide write access
    void setevent(Event value) {
        std::cout << "Event: " << this << std::endl;

        
    }

    //LOCATION accessor methods
    //getters - provide read access
    Location getlocation() {
        return this->location;
    }

    //setters - provide write access
    void setlocation(Location value) {
        std::cout << "Location: " << this << std::endl;
    }

    //TICKETTYPE accessor methods
    //getters - provide read access
    std::string getticketType() {
        return this->ticketType;
    }

    //setters - provide write access
    void setticketType(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->ticketType = value;
        }
        else {

            throw "Wrong value";

        }
    }

    
};