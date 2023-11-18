#pragma once
#include "masterheader.h"

class EventManager {//collection class
private:

    // List to store issued events
    std::vector<Event*> issuedEvent;//vector dinamic(nu incarca memoria)

    // Name of the data file for persisting event data
    std::string dataFileName;

    // Char array
    char charArray[100]; // Adjust the size accordingly

    // Char pointer
    char* charPointer;

public:

    EventManager() {//default constructor
        issuedEvent = {};
        dataFileName = "";
        charPointer = nullptr;
        std::strcpy(charArray, "DefaultCharArray");
    }

    // Constructor: Initialize EventManager with the data file name
    EventManager(const std::string& fileName, const char arr[], const char* ptr) : dataFileName(fileName), charPointer(nullptr) {
        // No need to explicitly initialize issuedEvent; it will be default-constructed.
        std::strcpy(charArray, arr);

        // Assuming char pointer is pointing to a null-terminated string
        charPointer = new char[std::strlen(ptr) + 1];
        std::strcpy(charPointer, ptr);
    }

    // Destructor to free memory allocated for charPointer
    ~EventManager() {
        delete[] charPointer;
    }

    //ISSUED EVENT accessor methods
     //getters - provide read access
    std::vector<Event*> getIssuedEvent() const{
        return this->issuedEvent;
    }

    //setters - provide write access
    void setissuedEvent(const std::vector<Event*>& IssuedEvent) {
        std::cout << "IssuedEvent: " << this << std::endl;
    }

    //DATAFILENAME accessor methods
    //getters - provide read access
    std::string getdataFileName() const{
        return this->dataFileName;
    }

    //setters - provide write access
    void setDataFileName(const std::string& fileName) {
        // ALWAYS validate the input
        if (!fileName.empty()) {
            dataFileName = fileName;
        }
        else {
            throw std::invalid_argument("Invalid file name");
        }
    }

    // CHARARRAY accessor methods
    // Getters - provide read access
    const char* getCharArray() const {
        return charArray;
    }

    // Setters - provide write access
    void setCharArray(const char arr[]) {
        // Assuming charArray is null-terminated
        std::strcpy(charArray, arr);
    }

    // CHARPOINTER accessor methods
    // Getters - provide read access
    const char* getCharPointer() const {
        return charPointer;
    }

    // Setters - provide write access
    void setCharPointer(const char* ptr) {
        // Free the existing memory before assigning a new pointer
        delete[] charPointer;

        // Assuming char pointer is pointing to a null-terminated string
        charPointer = new char[std::strlen(ptr) + 1];
        std::strcpy(charPointer, ptr);
    }

};
