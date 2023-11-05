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

  };