// Author: Tushardeep Singh
// Seneca College Alumni

#include "./event.h"

namespace seneca
{
  // Global variable
  size_t g_sysClock{0};

  // Default Constructor
  Event::Event()
  {
    std::strcpy(m_eventDescription, "\0");
    m_eventStartTime = 0;
  }

  // Sets the object to empty state
  void Event::setEmpty()
  {
    std::strcpy(m_eventDescription, "\0");
    m_eventStartTime = 0;
  }

  void Event::display()
  {
    // Static variable
    static int counter = 0;
    std::cout << std::setw(2) << std::right << ++counter;
    std::cout << ". ";
    if (std::strcmp(m_eventDescription, "\0") == 0)
    {
      std::cout << "| No Event |\n";
      return;
    }
    // Convert to hours, minutes and seconds
    int hours = m_eventStartTime / (60 * 60);
    int minutes = (m_eventStartTime / 60) % 60;
    int seconds = m_eventStartTime % 60;
    std::cout << std::setfill('0') << std::setw(2) << std::right << hours;
    std::cout << ':';
    std::cout << std::setfill('0') << std::setw(2) << std::right << minutes;
    std::cout << ':';
    std::cout << std::setfill('0') << std::setw(2) << std::right << seconds;
    std::cout << std::setfill(' ');
    std::cout << " => " << m_eventDescription << '\n';
  }

  void Event::set(const char arr[])
  {
    if (arr == NULL || !arr[0])
    {
      setEmpty();
      return;
    }
    // arr contains the description
    std::strcpy(m_eventDescription, arr);
    // g_sysClock contains the time
    m_eventStartTime = g_sysClock;
  }

  // Copy constructor
  Event::Event(const Event& other)
  {
    std::strcpy(m_eventDescription, other.m_eventDescription);
    m_eventStartTime = other.m_eventStartTime;
  }

  // Copy assignment operator
  Event& Event::operator=(const Event& other)
  {
    std::strcpy(m_eventDescription, other.m_eventDescription);
    m_eventStartTime = other.m_eventStartTime;
    return *this;
  }

  // Destructor
  Event::~Event()
  {
    std::strcpy(m_eventDescription, "\0");
    m_eventStartTime = 0;
  }
}