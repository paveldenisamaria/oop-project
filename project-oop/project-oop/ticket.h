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

    friend std::ifstream& operator>>(std::ifstream& file, Location& location);




    static const int MIN_DESCRIPTION = 5;

   
    //default constructor 
    Ticket() : id(0), event(), location(), description(nullptr) ,ticketType(){
        uniqueIDCounter = 0;
        strcpy_s(ticketType, "");
        Ticket::NO_TICKETS += 1;
    }


    // Constructor: Initialize the Ticket object with provided values.
    Ticket(int id, const Event& event, const Location& location, const char* ticketType, const char* description) : id(id), event(event), location(location) {
        this->setdescription(description);
        this->setticketType(ticketType);
        Ticket::NO_TICKETS += 1;
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


    void readFromFile(std::ifstream& file);
    void writeToFile(std::ofstream& file) const;
};

void Ticket::readFromFile(std::ifstream& file) {
    if (!file.is_open()) {
        std::cerr << "Error: File is not open." << std::endl;
        return;
    }

    // Read and assign values from the file
    file >> id;

    // Read the event data
    std::string eventDate, eventTime, eventName;
    file >> eventDate >> eventTime;
    file.ignore(); // Consume the space after eventTime
    std::getline(file, eventName);

    // Set the event attributes
    event.setdate(eventDate);
    event.settime(eventTime.c_str());
    event.setname(eventName.c_str());

    // Read the location data
    file >> location;

    // Read ticketType and description
    file >> ticketType;
    char buffer[256];  // Adjust the size based on your needs
    file.getline(buffer, 256);  // Consume the newline character
    file.getline(buffer, 256);  // Read the description
    setdescription(buffer);
}


void Ticket::writeToFile(std::ofstream& file) const {
    file << id << ' ' << event << ' ' << location << ' ' << ticketType << '\n';
    file << description << '\n';
}

std::ifstream& operator>>(std::ifstream& file, Location& location) {
    if (!file.is_open()) {
        std::cerr << "Error: File is not open." << std::endl;
        return file;
    }

    // Read and assign values from the file
    file >> location.id >> location.maxSeats >> location.numRows;

    // Read nrSeatsRow
    for (int i = 0; i < location.numRows; ++i) {
        file >> location.nrSeatsRow[i];
    }

    char buffer[MAX_LOCSIZE];
    file.ignore();  // Consume the newline character after numRows
    file.getline(buffer, MAX_LOCSIZE);  // Read the location name
    location.setnamelocation(buffer);

    return file;
}

std::ostream& operator<<(std::ostream& os, const Location& location) {
    // Implement the output logic for the Location class
    os << "ID: " << location.id << "\n";
    // ... output other members ...

    return os;
}

int Ticket::NO_TICKETS = 0;