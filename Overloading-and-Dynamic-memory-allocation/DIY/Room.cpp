// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Room.h"

namespace seneca
{
  void set(Room &room, int numberOfGuests, const char *roomNumber)
  {
    strcpy(room.m_roomNumber, roomNumber);
    room.m_noOfGuests = numberOfGuests;
    // Allocate guests array dynamically
    room.m_guests = new Guest[room.m_noOfGuests];
    for (int i = 0; i < room.m_noOfGuests; ++i)
      setToDefault(room.m_guests[i]);
  }

  void print(const Room &room)
  {
    if(!room.m_noOfGuests)
    {
      std::cout << "Empty Room!\n";
      return;
    }

    std::cout << "Room Number: " << room.m_roomNumber << '\n';
    for (int i = 0; i < room.m_noOfGuests; ++i)
    {
      std::cout << "    ";
      print(room.m_guests[i]);
    }
  }

  void vacate(Room &room)
  {
    // Deallocate memory occupied by guests and it's array
    for (int i = 0; i < room.m_noOfGuests; ++i)
      vacate(room.m_guests[i]);
    delete[] room.m_guests;
    room.m_guests = nullptr;

    room.m_noOfGuests = 0;
    const char* zero = "0";
    strcpy(room.m_roomNumber, zero);
  }

  void book(Room& room)
  {
    // Get the input from the console and store the values
    std::cout << "Room number: ";
    std::cin >> room.m_roomNumber;
    std::cout << "Number of guests: ";
    std::cin >> room.m_noOfGuests;
    room.m_guests = new Guest[room.m_noOfGuests];
    for(int i = 0;i < room.m_noOfGuests; ++i)
    {
      std::cout << (i + 1) << ":\n";
      book(room.m_guests[i]);
    } 
  }
}