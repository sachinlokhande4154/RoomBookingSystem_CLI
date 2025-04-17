
#include "RoomBookingSystem.h"


RoomBookingSystem::RoomBookingSystem() {
    rooms[101] = { 101, "Lab", 10, false };
    rooms[102] = { 102, "Meeting", 8, false };
    rooms[103] = { 103, "Break Room", 6, false };
    rooms[104] = { 104, "Workspace", 20, false };
    rooms[105] = { 105, "Learn Deck", 12, false };
}

void RoomBookingSystem::bookRoom() {
    int roomNumber, chairs;
    string host, purpose, start, end;

    cout << "Enter Room Number: ";
    cin >> roomNumber;

    if (rooms.find(roomNumber) == rooms.end()) {
        cout << "Room not found!\n";
        return;
    }

    if (rooms[roomNumber].isBooked) {
        cout << "Room already booked.\n";
        return;
    }

    cout << "Enter Host Name: ";
    cin.ignore();
    getline(cin, host);
    cout << "Enter Purpose: ";
    getline(cin, purpose);
    cout << "Enter Start Time: ";
    getline(cin, start);
    cout << "Enter End Time: ";
    getline(cin, end);
    cout << "Enter Chairs Required: ";
    cin >> chairs;

    if (chairs > rooms[roomNumber].totalChairs) {
        cout << "Not enough chairs available.\n";
        return;
    }

    bookings.push_back({ roomNumber, host, purpose, start, end, chairs });
    rooms[roomNumber].isBooked = true;
    cout << "Room booked successfully!\n";
}

void RoomBookingSystem::checkRoomStatus() {
    int roomNumber;
    cout << "Enter Room Number to check: ";
    cin >> roomNumber;

    if (rooms.find(roomNumber) == rooms.end()) {
        setConsoleColor(12);  // Red
        cout << "Room not found!\n";
        setConsoleColor(7);
        return;
    }

    Room room = rooms[roomNumber];
    cout << "\nRoom " << room.roomNumber << " - " << room.purpose << "\n";
    cout << "Total Chairs: " << room.totalChairs << "\n";

    setConsoleColor(room.isBooked ? 12 : 10); // Red or Green
    cout << "Status: " << (room.isBooked ? "Booked" : "Available") << "\n";
    setConsoleColor(7);
}


void RoomBookingSystem::viewBookings() {
    if (bookings.empty()) {
        cout << "No bookings found.\n";
        return;
    }

    for (const auto& b : bookings) {
        cout << "\nRoom: " << b.roomNumber
            << "\nHost: " << b.hostName
            << "\nPurpose: " << b.purpose
            << "\nStart: " << b.startTime
            << "\nEnd: " << b.endTime
            << "\nChairs Booked: " << b.chairsBooked
            << "\n---------------------------";
    }
}

void RoomBookingSystem::cancelBooking() {
    int roomNumber;
    cout << "Enter Room Number to cancel booking: ";
    cin >> roomNumber;

    auto it = find_if(bookings.begin(), bookings.end(), [roomNumber](Booking& b) {
        return b.roomNumber == roomNumber;
        });

    if (it != bookings.end()) {
        bookings.erase(it);
        rooms[roomNumber].isBooked = false;
        cout << "Booking cancelled for Room " << roomNumber << "\n";
    }
    else {
        cout << "No booking found for this room.\n";
    }
}

void RoomBookingSystem::showMenu() {
    int choice;
    do {
        setConsoleColor(11);  // Aqua
        cout << "\n=== Room Booking System Menu ===\n";
        setConsoleColor(14);  // Yellow
        cout << "1. Book a Room\n";
        cout << "2. Check Room Status\n";
        cout << "3. View All Bookings\n";
        cout << "4. Cancel a Booking\n";
        cout << "5. Exit\n";
        setConsoleColor(7);   // Default
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: bookRoom(); break;
        case 2: checkRoomStatus(); break;
        case 3: viewBookings(); break;
        case 4: cancelBooking(); break;
        case 5:
            setConsoleColor(10);  // Green
            cout << "Exiting... Goodbye!\n";
            setConsoleColor(7);
            break;
        default:
            setConsoleColor(12);  // Red
            cout << "Invalid choice!\n";
            setConsoleColor(7);
        }
    } while (choice != 5);
}
