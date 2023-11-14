#pragma once
#include "masterheader.h"
#define MAX_LOCSIZE 1000
#define ID_MIN 1000000
#define MAX_NRSEATS 150000

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

    static const int MIN_NAME = 2;

    char* getserial() {//doar name e mobil restu sunt const
        int l = sizeof(id);
        int l = sizeof(maxSeats);
        int l = sizeof(numRows);
        l += strlen(namelocation);
        l += strlen(nrSeatsRow);

        char* bytes = new char[l + sizeof(int)];//un nr the bytes egal cu lungimea totala a datelor
        *(int*)bytes = l;
        strcpy_s(bytes + 4, strlen(nrSeatsRow) + 1, nrSeatsRow);
        strcpy_s(bytes + 14, strlen(namelocation) + 1, namelocation);

        return bytes;
    }

    Location() {//default constructor
        id = 0;
        numRows = 0;
        namelocation = nullptr;
        strcpy(nrSeatsRow, "");
    }

    // Constructor: Initialize the Location object with provided values.
    Location(int id,int maxSeats,int numRows, const char* nrSeatsRow,const char* namelocation) :  id(id),maxSeats(maxSeats),numRows(numRows) {
        numRows = strlen(nrSeatsRow);//atatea randuri cate locuri sunt

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
        return string(this->nrSeatsRow);//this is the correct way
    }

    //setters - provide write access
    void setnrSeatsRow(const char* value) {
        //ALWAYS validate the input
        if (value != nullptr) {
            strcpy_s(this->nrSeatsRow, strlen(value) + 1, value);
        }
        else {

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

        if (namelocation.size() <= Event::MIN_NAME) {
            throw exception("Name of the location too short");
        }

    }

    void setnamelocation(const char* namelocation) {
        this->namelocation = new char[strlen(namelocation) + 1];
        strcpy_s(this->namelocation, strlen(namelocation) + 1, namelocation);

        if (strlen(namelocation) <= Event::MIN_NAME) {
            throw exception("Name of the location too short");
        }

    }

    ~Location() {
        if (namelocation != nullptr) {
            delete[] namelocation;
        }
        Location::NO_LOCATION -= 1;

    }
  };