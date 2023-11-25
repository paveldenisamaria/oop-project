#pragma once
#include "masterheader.h"
#define MAX_TICKETTYPE 10
#define ID_MIN 1000000
using namespace std;



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
// Declare the operator<< as a friend
    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);

   //template <typename T>
   //friend  void displayAttribute( T& attribute);

    static const int MIN_DESCRIPTION = 5;

   
    //default constructor 
    Ticket() : id(0), event(), location(), description(nullptr) ,ticketType(){
        uniqueIDCounter = 0;
        strcpy_s(ticketType, "");
        Ticket::NO_TICKETS += 1;
    }


    // Constructor: Initialize the Ticket object with provided values.
    Ticket(int id,Event event, Location location,const char* ticketType,const char* description) :id(id){
        

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

    // Generic method to display all attributes of Ticket
    void displayAttributes() const {
        displayAttribute(id);
        event.displayAttributes();
        location.displayAttributes();
        displayAttribute(ticketType);
        displayAttribute(description);
    }

    // Generic method to process attributes of Ticket
    template <typename Processor>
    void processAttributes(Processor&& processor) {
        processor(id);
        event.processAttributes(processor);
        location.processAttributes(processor);
        processor(ticketType);
        processor(description);
    }

    // Copy assignment operator
    Ticket& operator=(const Ticket& other) {
        if (this != &other) {
            // Copy each member from 'other' to 'this'
            id = other.id;

            // Copy characters from 'other.ticketType' to 'this.ticketType'
            for (int i = 0; i < MAX_TICKETTYPE; ++i) {
                ticketType[i] = other.ticketType[i];
            }

            // Release existing memory for 'description' if any
            if (description != nullptr) {
                delete[] description;
            }

            // Allocate new memory for 'description' and copy the content
            description = new char[strlen(other.description) + 1];
            strcpy_s(description, strlen(other.description) + 1, other.description);

            // Copy 'event' and 'location'
            event = other.event;
            location = other.location;
        }
        return *this;
    }

    bool operator==(const Ticket& other) const {
        return (id == other.id) &&
            (event == other.event) &&
            (location == other.location) &&
            (strcmp(ticketType, other.ticketType) == 0) &&
            (strcmp(description, other.description) == 0);
    }
};

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
    // Implement the output logic for the Ticket class
    os << "ID: " << ticket.id << "\n";
    // ... output other members ...

    return os;
}

int Ticket::NO_TICKETS = 0;