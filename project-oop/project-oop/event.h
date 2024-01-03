#pragma once
#include "masterheader.h"
#include <exception>
#define MAX_TIME 9 //23:59:59 needs 8+1 characters
#define MAX_DATE 10
#define MAX_NAME 100
#define ID_MIN 1000000
using namespace std;

/* Generic function to display an attribute

template <typename T>
void displayAttribute(T& attribute) {
    cout << attribute << endl;
}
*/

// Function to display an attribute of type int
void displayAttribute(int attribute) {
    std::cout << attribute << std::endl;
}

// Function to display an attribute of type std::string
void displayAttribute(const std::string& attribute) {
    std::cout << attribute << std::endl;
}

// Function to display an attribute of type const char*
void displayAttribute(const char* attribute) {
    std::cout << attribute << std::endl;
}

// Function to process an attribute of type int
void processAttribute(int attribute) {
    // Custom processing logic for int attribute
    // For example, you can perform operations on the attribute
    std::cout << "Processing int attribute: " << attribute << std::endl;
}

// Function to process an attribute of type std::string
void processAttribute(const std::string& attribute) {
    // Custom processing logic for std::string attribute
    // For example, you can perform operations on the attribute
    std::cout << "Processing string attribute: " << attribute << std::endl;
}

// Function to process an attribute of type const char*
void processAttribute(const char* attribute) {
    // Custom processing logic for const char* attribute
    // For example, you can perform operations on the attribute
    std::cout << "Processing const char* attribute: " << attribute << std::endl;
}



class Event {
private:

    // Private member to store the id of the event.
    int id;
    // Private member to store the date of the event.
    std::string date;
    // Private member to store the time of the event.
    char timestart[MAX_TIME];
    // Private member to store the name of the event.
    char* name;

    static int NO_EVENTS;
    
    


public:

   // Declare the operator<< as a friend
    friend std::ostream& operator<<(std::ostream& os, const Event& event);

    
   //template <typename T>
   //friend  void displayAttribute( T& attribute);

    friend std::ifstream& operator>>(std::ifstream& file, Event& event);
    
    static const int MIN_NAME = 2;
    

    Event() {//default constructor
        id = 0;
        date = "";
        strcpy_s(timestart,"");
        name = nullptr;
    }

    // Constructor: Initialize the Event object with provided values.
    Event(const std::string& date, const char* timestart, const char* name, int id) :
        date(date), id(id) {

        this->setname(name);
        Event::NO_EVENTS += 1;

        this->settime(timestart);

    }

    // Copy constructor for Event
    Event(const Event& other) : date(other.date), id(other.id) {
        setname(other.name);
        settime(other.timestart);
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

    //DATE accessor methods
    //getters - provide read access
    std::string getdate() {
        return string(this->date);
    }

    //setters - provide write access
    void setdate(string value) {
       //12.03.1988
        this->date = value;
    }

    //TIME accessor methods
    //getters - provide read access
    std::string gettime() {
        return string (this->timestart);//this is the correct way
    }

    //setters - provide write access
    void settime(const char* value) {
        //ALWAYS validate the input
        if (value != nullptr) {
            strcpy_s(this->timestart, strlen(value)+1,value);
        }
        else {

            throw exception("NUll value");

        }
    }

    //NAME accessor methods
    //getters - provide read access
    std::string getname() {
        return string(this->name);
    }

    //setters - provide write access (for both situations)
    void setname(string name) {
        this->name = new char[name.size() + 1];
        strcpy_s(this->name, name.size() + 1, name.c_str());

        if (name.size() <= Event::MIN_NAME) {
            throw exception("Name too short");
        }
       
    }

    void setname(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        if (strlen(name) <= Event::MIN_NAME) {
            throw exception("Name too short");
        }
       
    }

    ~Event() {
        if (name != nullptr) {
            delete[] name;
        }
        Event::NO_EVENTS -= 1;

    }

    //Generic method to display all attributes of Event
    void displayAttributes() const {
        displayAttribute(id);
        displayAttribute(date);
        displayAttribute(timestart);
        displayAttribute(name);
    }
    

    // Generic method to process attributes of Event
    template <typename Processor>
    void processAttributes(Processor&& processor) {
        processor(id);
        processor(date);
        processor(timestart);
        processor(name);
    }

    // Copy assignment operator
    Event& operator=(const Event& other) {
        if (this != &other) {
            // Copy each member from 'other' to 'this'
            id = other.id;
            date = other.date;
            strcpy_s(timestart, other.timestart);

            // Release existing memory for 'name' if any
            if (name != nullptr) {
                delete[] name;
            }

            // Allocate new memory for 'name' and copy the content
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
        }
        return *this;
    }

    bool operator==(const Event& other) const {
        return (id == other.id) &&
            (date == other.date) &&
            (strcmp(timestart, other.timestart) == 0) &&
            (strcmp(name, other.name) == 0);
    }


    std::string getdate() const;
    std::string gettime() const;
    int getID() const;
    std::string getname() const;

    void readFromFile(std::ifstream& file);
    void writeToFile(std::ofstream& file) const;
};

std::string Event::getdate() const {
    return date;
}

std::string Event::gettime() const {
    return std::string(timestart);
}

int Event::getID() const {
    return id;
}

std::string Event::getname() const {
    return std::string(name);
}

void Event::readFromFile(std::ifstream& file) {
    if (!file.is_open()) {
        std::cerr << "Error: File is not open." << std::endl;
        return;
    }

    // Read and assign values from the file
    std::string dateString, timeString, name;
    int id;

    if (file >> id >> dateString >> timeString >> name) {
        // Assuming date, time, and name are separated by whitespace
        date = dateString;
        settime(timeString.c_str());
        setname(name);
        setID(id);
    }
    else {
        std::cerr << "Error: Failed to read Event data from the file." << std::endl;
    }
}

void Event::writeToFile(std::ofstream& file) const {
    if (!file.is_open()) {
        std::cerr << "Error: File is not open." << std::endl;
        return;
    }

    // Write Event data to the file
    file << getID() << " " << getdate() << " " << gettime() << " " << getname() << "\n";

}

// Outside the Event class definition
std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "Event ID: " << event.id << ", Date: " << event.date << ", Time: " << event.timestart << ", Name: " << event.name;
    return os;
}


std::istream& operator>>(std::istream& is, Event& event) {
    // Read and assign values from the input stream
    std::string dateString, timeString, name;
    int id;
    return is;
}



int Event::NO_EVENTS = 0;