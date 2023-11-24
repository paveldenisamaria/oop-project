
#include "masterheader.h"

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
                std::cout << "Enter date: ";
                std::cin >> date;
                std::cout << "Enter start time: ";
                std::cin >> timestart;
                std::cout << "Enter event name: ";
                std::cin >> name;
                std::cout << "Enter event ID: ";
                std::cin >> id;

                Event newEvent(date, timestart.c_str(), name.c_str(), id);
                events.push_back(newEvent);
                break;
            }
            case 2: {
                // Add Location
                int id, maxSeats, numRows;
                char nrSeatsRow[MAX_LOCSIZE];
                char namelocation[MAX_LOCSIZE];
                std::cout << "Enter location ID: ";
                std::cin >> id;
                std::cout << "Enter maximum seats: ";
                std::cin >> maxSeats;
                std::cout << "Enter number of rows: ";
                std::cin >> numRows;
                std::cout << "Enter seats per row (e.g., 321): ";
                std::cin >> nrSeatsRow;
                std::cout << "Enter location name: ";
                std::cin >> namelocation;

                Location newLocation(id, maxSeats, numRows, nrSeatsRow, namelocation);
                locations.push_back(newLocation);
                break;
            }
            case 3: {
                // Generate Ticket
                int eventIndex, locationIndex;
                std::string ticketType, description;
                std::cout << "Enter index of the event: ";
                std::cin >> eventIndex;
                std::cout << "Enter index of the location: ";
                std::cin >> locationIndex;
                std::cout << "Enter ticket type: ";
                std::cin >> ticketType;
                std::cout << "Enter ticket description: ";
                std::cin >> description;

                if (eventIndex >= 0 && eventIndex < events.size() &&
                    locationIndex >= 0 && locationIndex < locations.size()) {
                    Ticket newTicket(events[eventIndex], locations[locationIndex], ticketType.c_str(), description.c_str());
                    tickets.push_back(newTicket);
                }
                else {
                    std::cout << "Invalid event or location index.\n";
                }
                break;
            }
            case 4: {
                // Validate Ticket
                int ticketIndex;
                std::cout << "Enter index of the ticket: ";
                std::cin >> ticketIndex;

                if (ticketIndex >= 0 && ticketIndex < tickets.size()) {
                    // Implement validation logic here
                    std::cout << "Ticket validated!\n";
                }
                else {
                    std::cout << "Invalid ticket index.\n";
                }
                break;
            }
            case 5: {
                // Exit the program
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 5);

        return 0;
    }

