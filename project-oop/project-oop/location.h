#pragma once
#include "masterheader.h"

class Location {
private:
    // Private member to store the id number of the location.
    int id;

    // Private member to store the maximum number of seats.
    int maxSeats;

    // Private member to store the number of rows.
    int numRows;

    // Private member to store the number of seats in each row.
    std::vector<int> nrSeatsRow;//vector dinamic in care sunt locurile pe fiecare zona

public:



    Location() {//default constructor
        id = 0;
        nrSeatsRow = {};
    }

    // Constructor: Initialize the Location object with provided values.
    Location(int id, const std::vector<int>& nrSeatsRow) : nrSeatsRow(nrSeatsRow), id(id) {
        numRows = nrSeatsRow.size();//atatea randuri cate locuri sunt

        maxSeats = 0;

        int x;
        for (int i = 0; i < numRows; i++) {//x ia pe rand val din vector 
            x = nrSeatsRow[i];
            maxSeats += x;
        }
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

    //maxSeats accessor methods
    //getters - provide read access
    int getmaxSeats() {
        return this->maxSeats;
    }

    //setters - provide write access
    void setmaxSeats(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->maxSeats = value;
        }
        else {

            throw "Wrong value";

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
        if (value == !nullptr) {
            this->numRows = value;
        }
        else {

            throw "Wrong value";

        }
    }

    //nrSeatsRow accessor methods
    //getters - provide read access
    std::vector<int> getnrSeatsRow() {
        return this->nrSeatsRow;
    }

    //setters - provide write access
    void setnrSeatsRow(const std::vector<int>& value) {
        //ALWAYS validate the input
        if (!value.empty()) {
            this->nrSeatsRow = value;
        }
        else {

            throw std::invalid_argument("Wrong value");

        }
    }
  };