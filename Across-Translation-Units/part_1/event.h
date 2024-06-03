// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <iostream>
#include <iomanip>

namespace seneca
{
  // Global variable
  extern size_t g_sysClock;

  class Event
  {
  private:
    // Description of the event
    char m_eventDescription[128];
    // Time when the event starts
    int m_eventStartTime;
  public:
    // Default Constructor
    Event();
    // Displays to the screen the content of an `Event` instance
    void display();
    void set(const char arr[] = NULL);
    // Sets the current object members to empty state
    void setEmpty();
    // Copy Constructor
    Event(const Event& other);
    // Copy assignment operator
    Event& operator=(const Event& other);
    // Destructor
    ~Event();
  };
}

#endif