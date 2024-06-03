// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H

#include "./Guest.h"

namespace seneca
{
  struct Room
  {
    char m_roomNumber[6];
    int m_noOfGuests;
    // Dynamic array of guests
    Guest *m_guests;
  };

  // Sets the Room by allocating a dynamic array of guests and setting the room number 
  void set(Room& room, int numberOfGuests, const char* roomNumber);
  // Prints the room number and names of the guests
  void print(const Room& room);
  // Vacates the room by dallocating all the memory used
  void vacate(Room& room);
  // Books a room by receiving the room number, number of guests and the guest information
  void book(Room& room);
}

#endif