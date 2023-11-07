#pragma once
#include "masterheader.h"


class LocationManager {
private:

    // List to store issued events
    std::vector<Location*> issuedLocation;//vector dinamic(nu incarca memoria)

    // Name of the data file for persisting event data
    std::string dataFileName;

public:

    LocationManager() {//default constructor
        issuedLocation = {};
        dataFileName = {};
    }

    // Constructor: Initialize EventManager with the data file name
    LocationManager(const std::string& fileName) : dataFileName(fileName) {

    }

    //ID accessor methods
    //getters - provide read access
    std::vector<Location*> getissuedLocation() {
        return this->issuedLocation;
    }

    //setters - provide write access
    void setissuedLocation(int value) {
        //ALWAYS validate the input
        std::cout << "IssuedLocation: " << this << std::endl;  
    }

    //DATAFILENAME accessor methods
    //getters - provide read access
    std::string getdataFileName() {
        return this->dataFileName;
    }

    //setters - provide write access
    void setdataFileName(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->dataFileName = value;
        }
        else {

            throw "Wrong value";

        }
    }

};