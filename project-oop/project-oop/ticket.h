#pragma once
#include "masterheader.h"
#define MAX_TICKETTYPE 10
#define ID_MIN 1000000

class Ticket {
private:


    // Private member to store the unique ID of the ticket.
    int id;
    // Private member to store a pointer to the associated event.
    Event event;
    // Private member to store a pointer to the associated location.
    Location location;
    // Private member to store the type of the ticket.
    char ticketType[MAX_TICKETTYPE];

    char* description;//medical certificate,student id card,...

    // Static counter for generating unique IDs
    static int uniqueIDCounter;// Static member to keep track of the next unique ID.

    static int NO_TICKETS;


public:


    static const int MIN_DESCRIPTION = 5;


    Ticket() {//default constructor
        id = 0;
        event = {};
        location = {};
        strcpy(ticketType,"");
        description = nullptr;
        uniqueIDCounter = 0;
    }

    // Constructor: Initialize the Ticket object with provided values.
    Ticket(Event event, Location location, const char* ticketType,const char* description) :
        event(event), location(location) {
        // Generate a unique ID for the ticket.
        id = generateUniqueID();

        this->setdescription(description);
        Ticket::NO_TICKETS += 1;

        this->setticketType(ticketType);
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
        if (value <= ID_MIN) {
            this->id = value;
        }
        else {

            throw exception("Wrong id");

        }
    }

    //EVENT accessor methods
    //getters - provide read access
    Event getevent() {
        return this->event;
    }

    //setters - provide write access
    void setevent(Event event) {
        this->event = event;

    }

    //LOCATION accessor methods
    //getters - provide read access
    Location getlocation() {
        return this->location;
    }

    //setters - provide write access
    void setlocation(Location location) {
        this->location = location;
    }

    //TICKETTYPE accessor methods
    //getters - provide read access
    std::string getticketType() {
        return this->ticketType;
    }

    //setters - provide write access
    void setticketType(const char* value) {
        //ALWAYS validate the input
        if (value != nullptr) {
            strcpy_s(this->ticketType, strlen(value) + 1, value);
        }
        else {

            throw exception("NUll value");

        }
    }

    //DESCRIPTION accessor methods
    //getters - provide read access
    std::string getdescription() {
        return string(this->description);
    }

    //setters - provide write access (for both situations)
    void setdescription(string description) {
        this->description = new char[description.size() + 1];
        strcpy_s(this->description, description.size() + 1, description.c_str());

        if (description.size() <= Ticket::MIN_DESCRIPTION) {
            throw exception("Description too short");
        }

    }

    void setdescription(const char* description) {
        this->description = new char[strlen(description) + 1];
        strcpy_s(this->description, strlen(description) + 1, description);

        if (strlen(description) <= Ticket::MIN_DESCRIPTION) {
            throw exception("Description too short");
        }

    }

    ~Ticket() {
        if (description != nullptr) {
            delete[] description;
        }
        Ticket::NO_TICKETS -= 1;

    }

    
};