#pragma once
#include "masterheader.h"
#define MAX_LOCSIZE 10000
#define ID_MIN 1000000
#define MAX_NRSEATS 150000
using namespace std;



class Location {
private:
    // Private member to store the id number of the location.
    int id;

    // Private member to store the maximum number of seats.
    int maxSeats;

    // Private member to store the number of rows.
    int numRows;

    // Private member to store the number of seats in each row.
    char nrSeatsRow[MAX_LOCSIZE];

    char* namelocation;

    static int NO_LOCATION;



public:

    // Declare the operator<< as a friend
    friend std::ostream& operator<<(std::ostream& os, const Location& location);

    //template <typename T>
    //friend  void displayAttribute(T& attribute);

    static const int MIN_NAME = 2;

   

    // Default constructor for the Location class
    Location() : id(0), maxSeats(0), numRows(0),nrSeatsRow(), namelocation(nullptr) {
        Location::NO_LOCATION += 1;
        strcpy_s(nrSeatsRow, "");
    }


    // Constructor: Initialize the Location object with provided values.
    Location(int id,int maxSeats,int numRows, const char* nrSeatsRow,const char* namelocation) :  id(id),maxSeats(maxSeats),numRows(numRows) {
        numRows = sizeof(nrSeatsRow);//atatea randuri cate locuri sunt

        maxSeats = 0;

        int x;
        for (int i = 0; i < numRows; i++) {//x ia pe rand val din vector 
            x = nrSeatsRow[i];
            maxSeats += x;
        }

        this->setnamelocation(namelocation);
        Location::NO_LOCATION += 1;

        this->setnrSeatsRow(nrSeatsRow);
    }

    // Copy constructor for Location
    Location(const Location& other) : id(other.id), maxSeats(other.maxSeats), numRows(other.numRows) {
        setnamelocation(other.namelocation);
        setnrSeatsRow(other.nrSeatsRow);
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

    //maxSeats accessor methods
    //getters - provide read access
    int getmaxSeats() {
        return this->maxSeats;
    }

    //setters - provide write access
    void setmaxSeats(int value) {
        //ALWAYS validate the input
        if (value < MAX_NRSEATS) {
            this->maxSeats = value;
        }
        else {

            throw exception("Impossible nr of seats"); 

        }
    }

    //numRows accessor methods
    //getters - provide read access
    int getnumRows() {
        return this->numRows;
    }

    //setters - provide write access
    void setnumRows(int value) {
        //ALWAYS validate the input
        if (value < MAX_LOCSIZE) {
            this->numRows = value;
        }
        else {

            throw exception("Impossible nr of rows");

        }
    }

    //nrSeatsRow accessor methods
    //getters - provide read access
    std::string getnrSeatsRow() {
        return string(this->nrSeatsRow);
    }

    //setters - provide write access
    void setnrSeatsRow(const char* value) {
        //ALWAYS validate the input
        if (value == nullptr) {
            throw exception("NUll value");
        }
        
    }

    //NAME accessor methods
    //getters - provide read access
    std::string getnamelocation() {
        return string(this->namelocation);
    }

    //setters - provide write access (for both situations)
    void setnamelocation(string namelocation) {
        this->namelocation = new char[namelocation.size() + 1];
        strcpy_s(this->namelocation, namelocation.size() + 1, namelocation.c_str());

        if (namelocation.size() <= Location::MIN_NAME) {
            throw exception("Name of the location too short");
        }

    }

    void setnamelocation(const char* namelocation) {
        this->namelocation = new char[strlen(namelocation) + 1];
        strcpy_s(this->namelocation, strlen(namelocation) + 1, namelocation);

        if (strlen(namelocation) <= Location::MIN_NAME) {
            throw exception("Name of the location too short");
        }

    }

    ~Location() {
        if (namelocation != nullptr) {
            delete[] namelocation;
        }
        Location::NO_LOCATION -= 1;

    }

    // Generic method to display all attributes of Location
    void displayAttributes() const {
        displayAttribute(id);
        displayAttribute(maxSeats);
        displayAttribute(numRows);
        displayAttribute(nrSeatsRow);
        displayAttribute(namelocation);
    }

    // Generic method to process attributes of Location
    template <typename Processor>
    void processAttributes(Processor&& processor) {
        processor(id);
        processor(maxSeats);
        processor(numRows);
        processor(nrSeatsRow);
        processor(namelocation);
    }

    // Copy assignment operator
    Location& operator=(const Location& other) {
        if (this != &other) {
            // Copy each member from 'other' to 'this'
            id = other.id;
            maxSeats = other.maxSeats;
            numRows = other.numRows;

            // Copy characters from 'other.nrSeatsRow' to 'this.nrSeatsRow'
            for (int i = 0; i < MAX_LOCSIZE; ++i) {
                nrSeatsRow[i] = other.nrSeatsRow[i];
            }

            // Release existing memory for 'namelocation' if any
            if (namelocation != nullptr) {
                delete[] namelocation;
            }

            // Allocate new memory for 'namelocation' and copy the content
            namelocation = new char[strlen(other.namelocation) + 1];
            strcpy_s(namelocation, strlen(other.namelocation) + 1, other.namelocation);
        }
        return *this;
    }

    // Overloaded equality operator ==
    bool operator==(const Location& other) const {
        return (id == other.id) &&
            (maxSeats == other.maxSeats) &&
            (numRows == other.numRows) &&
            (strcmp(nrSeatsRow, other.nrSeatsRow) == 0) &&
            (strcmp(namelocation, other.namelocation) == 0);
    }

  };

  std::ostream& operator<<(std::ostream& os, const Location& location) {
      // Implement the output logic for the Location class
      os << "ID: " << location.id << "\n";
      // ... output other members ...

      return os;
  }

  int Location::NO_LOCATION = 0;