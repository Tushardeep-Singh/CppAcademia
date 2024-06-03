// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <chrono>
#include <iostream>
#include <iomanip>

namespace seneca
{
  const int MAX_EVENT_OBJECTS = 10;

  class TimedEvents
  {
  private:
    // Number of records currently stored
    int m_numCurrEvents{0};
    // Start time for the current event
    std::chrono::time_point<std::chrono::steady_clock> m_eventStartTime{};
    // End time for the current event
    std::chrono::time_point<std::chrono::steady_clock> m_eventEndTime{};
    struct Event
    {
      char *m_eventName{nullptr};
      char *m_unitsOfTime{nullptr};
      // Duration of the event
      std::chrono::nanoseconds m_duration{};
    };
    Event m_events[MAX_EVENT_OBJECTS]{};

  public:
    // Default Constructor
    TimedEvents();
    // Starts the timer for an event
    void startClock();
    // Stops the timer for an event
    void stopClock();
    // Updates the next time-record in the array
    void addEvent(const char *eventName);
    // Inserts in the std::ostream object the records from the array
    friend std::ostream &operator<<(std::ostream &output, const TimedEvents &outputTimedEvents);
    // Rule of 3
    // Destructor
    ~TimedEvents();
    // Copy Constructor
    TimedEvents(const TimedEvents &other);
    // Copy Assignment operator
    TimedEvents &operator=(const TimedEvents &other);
  };
}
#endif