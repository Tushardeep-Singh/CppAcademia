// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_LIBRARY_ITEM_H
#define SENECA_LIBRARY_ITEM_H

#include <cstring>
#include <iostream>

namespace seneca
{
  class LibraryItem
  {
  private:
    // Title of the item
    char *m_title{nullptr};
    // Publication year of the item
    int m_year{0};

  public:
    // Default constructor
    LibraryItem();
    // Parameterized constructor
    LibraryItem(const char *title, int year);
    // Copy constructor
    LibraryItem(const LibraryItem &other);
    // Copy assignment operator
    LibraryItem &operator=(const LibraryItem &other);
    // Virtual distructor
    virtual ~LibraryItem();

    // Getters
    // Returns m_title
    char *getTitle() const;
    // Returns m_year
    int getYear() const;

    // Setters
    // Sets m_title
    void setTitle(const char *title);
    // Sets m_year
    void setYear(int year);

    // Displays the title and year of the library item
    virtual std::ostream &display(std::ostream &ostr = std::cout) const;
  };
}

#endif