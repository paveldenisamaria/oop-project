#pragma once
#include "masterheader.h"

class Event {
private:

    // Private member to store the id of the event.
    int id;
    // Private member to store the date of the event.
    std::string date;
    // Private member to store the time of the event.
    std::string time;
    // Private member to store the name of the event.
    std::string name;

public:

    Event() {//default constructor
        id = 0;
        date = "";
        time = "";
        name = "";
    }

    // Constructor: Initialize the Event object with provided values.
    Event(const std::string& date, const std::string& time, const std::string& name, int id) :
        date(date), time(time), name(name), id(id) {}

    //ID accessor methods
    //getters - provide read access
    int getID() {
        return this->id;
    }

    //setters - provide write access
    void setID(int value) {
        //ALWAYS validate the input
        if (value ==! nullptr ) {
            this->id = value;
        }
        else {
            
            throw "Wrong value";
            
        }
    }

    //DATE accessor methods
    //getters - provide read access
    std::string getdate() {
        return this->date;
    }

    //setters - provide write access
    void setdate(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->date = value;
        }
        else {

            throw "Wrong value";

        }
    }

    //TIME accessor methods
    //getters - provide read access
    std::string gettime() {
        return this->time;
    }

    //setters - provide write access
    void settime(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->time = value;
        }
        else {

            throw "Wrong value";

        }
    }

    //NAME accessor methods
    //getters - provide read access
    std::string getname() {
        return this->name;
    }

    //setters - provide write access
    void setname(int value) {
        //ALWAYS validate the input
        if (value == !nullptr) {
            this->name = value;
        }
        else {

            throw "Wrong value";

        }
    }

};