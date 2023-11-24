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

   
    //default constructor 
    Ticket() { 
        id = 0;
        description = nullptr;
        uniqueIDCounter = 0;
        strcpy_s(ticketType, "");
    }

    // Constructor: Initialize the Ticket object with provided values.
    Ticket(Event event, Location location,const char* ticketType,const char* description) {
        

        this->setdescription(description);
        Ticket::NO_TICKETS += 1;

        this->setticketType(ticketType);

        
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

  /* //EVENT accessor methods
            // Getter and setter for Event
            Event getEvent() const {
                return event;
            }

            void setEvent(const Event& newEvent) {
                event = newEvent;
            }


    //LOCATION accessor methods
            // Getter and setter for Location
            Location getLocation() const {
                return location;
            }

            void setLocation(const Location& newLocation) {
                location = newLocation;
            }
*/ 


    //TICKETTYPE accessor methods
            //getters - provide read access
            std::string getticketType() const{
                return this->ticketType;
            }

            //setters - provide write access
            void setticketType(const char* value) {
                //ALWAYS validate the input
                if (value == nullptr) {
                    throw std::invalid_argument("Null value");
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