// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca
{
  class Book
  {
  private:
    std::string m_bookAuthor;
    std::string m_bookTitle;
    std::string m_bookPublicationCountry;
    size_t m_bookPublicationYear;
    double m_bookPrice;
    std::string m_bookDescription;

  public:
    // Default Constructor
    Book();
    // Getter: returns the book title
    const std::string &title() const;
    // Getter: returns the book publication country
    const std::string &country() const;
    // Getter: returns the book publication year
    const size_t &year() const;
    // Getter: returns the price of the book
    const double &price() const;
    // Getter: returns the author of the book
    const std::string& getBookAuthor() const;
    // Getter: returns the book description
    const std::string& getBookDescription() const;
    // 1-arg constructor
    Book(const std::string &strBook);
    // Removes leading and trailing white spaces from the param str
    void removeLeadTrailWhiteSpace(std::string &str) const;
    // Copy assignment operator
    Book& operator=(const Book& copyFromBook);
    // Setter: sets the price of the book (m_bookPrice) to param price
    void setBookPrice(const double& price);
  };
  // Overloading the insertion operator
  std::ostream &operator<<(std::ostream &output, const Book &outputBook);
}

#endif