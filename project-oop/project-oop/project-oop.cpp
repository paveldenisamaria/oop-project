
#include "masterheader.h"
using namespace std;

// Generic function to display an attribute



int main() {

        std::vector<Event> events;
        std::vector<Location> locations;
        std::vector<Ticket> tickets;

        int choice;

        do {
            std::cout << "1. Add Event\n";
            std::cout << "2. Add Location\n";
            std::cout << "3. Generate Ticket\n";
            std::cout << "4. Validate Ticket\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                // Add Event
                std::string date, timestart, name;
                int id;
                std::cout << "\nEnter date: ";
                std::cin >> date;
                std::cout << "\nEnter start time: ";
                std::cin >> timestart;
                std::cout << "\nEnter event name: ";
                std::cin >> name;
                std::cout << "\nEnter event ID: ";
                std::cin >> id;

                Event newEvent(date, timestart.c_str(), name.c_str(), id);
                events.push_back(newEvent);
                events.back().displayAttributes();
                events.back().processAttributes([](const auto& attribute) {
                    // Custom processing logic for Event attributes
                    // For example, you can perform operations on each attribute
                    // ...
                    });
                break;


            }
            case 2: {
                // Add Location
                int id, maxSeats, numRows;
                char nrSeatsRow[MAX_LOCSIZE];
                char namelocation[MAX_LOCSIZE];
                std::cout << "\nEnter location ID: ";
                std::cin >> id;
                std::cout << "\nEnter maximum seats: ";
                std::cin >> maxSeats;
                std::cout << "\nEnter number of rows: ";
                std::cin >> numRows;
                std::cout << "\nEnter seats per row (e.g., 321): ";
                std::cin >> nrSeatsRow;
                std::cout << "\nEnter location name: ";
                std::cin >> namelocation;

                Location newLocation(id, maxSeats, numRows, nrSeatsRow, namelocation);
                locations.push_back(newLocation);
                locations.back().displayAttributes();
                locations.back().processAttributes([](const auto& attribute) {
                    // Custom processing logic for Location attributes
                    // ...
                    });
                break;
            }
            case 3: {
                // Generate Ticket
                int eventIndex, locationIndex;
                std::string ticketType, description;
                std::cout << "\nEnter index of the event: ";
                std::cin >> eventIndex;
                std::cout << "\nEnter index of the location: ";
                std::cin >> locationIndex;
                std::cout << "\nEnter ticket type: ";
                std::cin >> ticketType;
                std::cout << "\nEnter ticket description: ";
                std::cin >> description;

                if (eventIndex >= 0 && eventIndex < events.size() &&
                    locationIndex >= 0 && locationIndex < locations.size()) {
                    Ticket newTicket(ID_MIN+eventIndex,events[eventIndex], locations[locationIndex], ticketType.c_str(), description.c_str());
                    tickets.push_back(newTicket);
                }
                else {
                    std::cout << "\nInvalid event or location index.\n";
                }
                tickets.back().displayAttributes();
                tickets.back().processAttributes([](const auto& attribute) {
                    // Custom processing logic for Ticket attributes
                    // ...
                    });
                break;
            }
            case 4: {
                // Validate Ticket
                int ticketIndex;
                std::cout << "\nEnter index of the ticket: ";
                std::cin >> ticketIndex;

                if (ticketIndex >= 0 && ticketIndex < tickets.size()) {
                    // Implement validation logic here
                    std::cout << "\nTicket validated!\n";
                }
                else {
                    std::cout << "\nInvalid ticket index.\n";
                }
                break;
            }
            case 5: {
                // Exit the program
                break;
            }
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
            }

        } while (choice != 5);

        return 0;
    }

