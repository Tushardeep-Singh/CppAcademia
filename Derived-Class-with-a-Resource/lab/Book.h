// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "./LibraryItem.h"

namespace seneca
{
  class Book : public LibraryItem
  {
  private:
    // Name of the author of the book
    char *m_author{nullptr};

  public:
    // Default constructor
    Book();
    // Parameterized constructor
    Book(const char *title, int year, const char *author);
    // Virtual destructor
    virtual ~Book();
    // Copy constructor
    Book(const Book &otherBook);
    // Getter, returns m_author
    char *getAuthor() const;
    // Copy assignment operator
    Book &operator=(const Book &otherBook);
    // Setter, sets m_author
    void setAuthor(const char *author);
    // Displays the title, year, and author of the book
    std::ostream &display(std::ostream &ostr = std::cout) const;
    // Checks to see if the object's author name is lexicographically greater than the other object's author name
    bool operator>(const Book &other) const;
  };
}

#endif