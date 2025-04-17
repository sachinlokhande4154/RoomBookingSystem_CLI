#ifndef ROOMBOOKINGSYSTEM_H
#define ROOMBOOKINGSYSTEM_H

#include <windows.h>

inline void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Room {
    int roomNumber;
    string purpose;
    int totalChairs;
    bool isBooked;
};

struct Booking {
    int roomNumber;
    string hostName;
    string purpose;
    string startTime;
    string endTime;
    int chairsBooked;
};

class RoomBookingSystem {
private:
    unordered_map<int, Room> rooms;
    vector<Booking> bookings;

public:
    RoomBookingSystem();
    void bookRoom();
    void checkRoomStatus();
    void viewBookings();
    void cancelBooking();
    void showMenu();
};

#endif // ROOMBOOKINGSYSTEM_H ✅ End of include guard
