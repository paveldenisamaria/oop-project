#pragma once
#include "masterheader.h"
#include <exception>
#define MAX_TIME 9 //23:59:59 needs 8+1 characters
#define ID_MIN 1000000

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

    char* getserial() {//doar name e mobil restu sunt const
        int l = sizeof(id);
        l += date.size();
        l += strlen(timestart);
        l += strlen(name);
        int l = sizeof(NO_EVENTS);
       
        char* bytes = new char [l+sizeof(int)];//un nr the bytes egal cu lungimea totala a datelor
        *(int*)bytes = l;
        strcpy_s(bytes + 4, date.size()+1, date.c_str());
        strcpy_s(bytes + 14, strlen(timestart) + 1, timestart);
        strcpy_s(bytes + 22, strlen(name) + 1, name);
       

        return bytes;
    }

    
    static const int MIN_NAME = 2;
    

    Event() {//default constructor
        id = 0;
        date = "";
        strcpy(timestart,"");
        name = nullptr;
    }

    // Constructor: Initialize the Event object with provided values.
    Event(const std::string& date, const char* timestart, const char* name, int id) :
        date(date), id(id) {

        this->setname(name);
        Event::NO_EVENTS += 1;

        this->settime(timestart);

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
};