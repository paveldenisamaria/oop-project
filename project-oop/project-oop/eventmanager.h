#pragma once
#include "masterheader.h"

class EventManager {
private:

    // List to store issued events
    std::vector<Event*> issuedEvent;//vector dinamic(nu incarca memoria)

    // Name of the data file for persisting event data
    std::string dataFileName;

public:

    EventManager() {//default constructor
        issuedEvent = {};
        dataFileName = "";
       
    }

    // Constructor: Initialize EventManager with the data file name
    EventManager(const std::string& fileName) : dataFileName(fileName) {
    }

    //ISSUED EVENT accessor methods
     //getters - provide read access
    std::vector<Event*> getissuedEvent() {
        return this->issuedEvent;
    }

    //setters - provide write access
    void setissuedEvent(int value) {
        std::cout << "IssuedEvent: " << this << std::endl;
    }

    //DATAFILENAME accessor methods
    //getters - provide read access
    std::string getdataFileName() {
        return this->dataFileName;
    }

    //setters - provide write access
    void setID(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->dataFileName = value;
        }
        else {

            throw "Wrong value";

        }
    }

};
