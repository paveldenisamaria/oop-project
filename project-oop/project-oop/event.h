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

};