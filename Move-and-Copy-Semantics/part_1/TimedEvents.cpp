// Author: Tushardeep Singh
// Seneca College Alumni

#include "TimedEvents.h"

namespace seneca
{
  // Default Constructor
  TimedEvents::TimedEvents()
  {
    m_numCurrEvents = 0;
  };

  // Starts the timer for an event
  void TimedEvents::startClock()
  {
    m_eventStartTime = std::chrono::steady_clock::now();
  }

  // Stops the timer for an event
  void TimedEvents::stopClock()
  {
    m_eventEndTime = std::chrono::steady_clock::now();
  }

  // Updates the next time-record in the array
  void TimedEvents::addEvent(const char *eventName)
  {
    m_events[m_numCurrEvents].m_eventName = new char[std::strlen(eventName) + 1];
    std::strcpy(m_events[m_numCurrEvents].m_eventName, eventName);
    m_events[m_numCurrEvents].m_unitsOfTime = new char[std::strlen("nanoseconds") + 1];
    std::strcpy(m_events[m_numCurrEvents].m_unitsOfTime, "nanoseconds");
    m_events[m_numCurrEvents].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_eventEndTime - m_eventStartTime);
    ++m_numCurrEvents;
  }

  // Inserts in the std::ostream object the records from the array
  std::ostream &operator<<(std::ostream &output, const TimedEvents &outputTimedEvents)
  {
    output << "--------------------------\n";
    output << "Execution Times:\n";
    output << "--------------------------\n";
    for (int i = 0; i < outputTimedEvents.m_numCurrEvents; ++i)
    {
      output << "  ";
      output << std::setw(21) << std::left << outputTimedEvents.m_events[i].m_eventName;
      output << std::setw(12) << std::right << outputTimedEvents.m_events[i].m_duration.count();
      output << ' ' << outputTimedEvents.m_events[i].m_unitsOfTime << '\n';
    }

    return output;
  }

  // Destructor
  TimedEvents::~TimedEvents()
  {
    for (int i = 0; i < m_numCurrEvents; ++i)
    {
      if (m_events[i].m_eventName != nullptr)
      {
        delete[] m_events[i].m_eventName;
        m_events[i].m_eventName = nullptr;
      }
      if (m_events[i].m_unitsOfTime != nullptr)
      {
        delete[] m_events[i].m_unitsOfTime;
        m_events[i].m_unitsOfTime = nullptr;
      }
      m_events[i].m_duration = static_cast<std::chrono::nanoseconds>(0);
    }
    m_numCurrEvents = 0;
    m_eventStartTime = std::chrono::time_point<std::chrono::steady_clock>{};
    m_eventEndTime = std::chrono::time_point<std::chrono::steady_clock>{};
  }

  // Copy constructor
  TimedEvents::TimedEvents(const TimedEvents &other)
  {
    m_numCurrEvents = other.m_numCurrEvents;
    m_eventStartTime = other.m_eventStartTime;
    m_eventEndTime = other.m_eventEndTime;

    for (int i = 0; i < m_numCurrEvents; ++i)
    {
      m_events[i].m_duration = other.m_events[i].m_duration;
      m_events[i].m_eventName = new char[std::strlen(other.m_events[i].m_eventName) + 1];
      std::strcpy(m_events[i].m_eventName, other.m_events[i].m_eventName);
      m_events[i].m_unitsOfTime = new char[std::strlen(other.m_events[i].m_unitsOfTime) + 1];
      std::strcpy(m_events[i].m_unitsOfTime, other.m_events[i].m_unitsOfTime);
    }
  }

  // Copy Assignment operator
  TimedEvents &TimedEvents::operator=(const TimedEvents &other)
  {
    m_numCurrEvents = other.m_numCurrEvents;
    m_eventStartTime = other.m_eventStartTime;
    m_eventEndTime = other.m_eventEndTime;
    for (int i = 0; i < m_numCurrEvents; ++i)
    {
      m_events[i].m_duration = other.m_events[i].m_duration;
      if (m_events[i].m_eventName != nullptr)
      {
        delete[] m_events[i].m_eventName;
        m_events[i].m_eventName = nullptr;
      }
      if (m_events[i].m_unitsOfTime != nullptr)
      {
        delete[] m_events[i].m_unitsOfTime;
        m_events[i].m_unitsOfTime = nullptr;
      }
      m_events[i].m_eventName = new char[std::strlen(other.m_events[i].m_eventName) + 1];
      std::strcpy(m_events[i].m_eventName, other.m_events[i].m_eventName);

      m_events[i].m_unitsOfTime = new char[std::strlen(other.m_events[i].m_unitsOfTime) + 1];
      std::strcpy(m_events[i].m_unitsOfTime, other.m_events[i].m_unitsOfTime);
    }

    return *this;
  }
}