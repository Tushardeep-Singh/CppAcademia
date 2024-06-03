// Author: Tushardeep Singh
// Seneca College Alumni

#include "Book.h"

namespace seneca
{
  Book::Book()
  {
    // Setting member variables to default value
    m_bookAuthor = "";
    m_bookTitle = "";
    m_bookPublicationCountry = "";
    m_bookPublicationYear = 0;
    m_bookPrice = 0.0;
    m_bookDescription = "";
  }

  const std::string &Book::title() const
  {
    return m_bookTitle;
  }

  const std::string &Book::country() const
  {
    return m_bookPublicationCountry;
  }

  const size_t &Book::year() const
  {
    return m_bookPublicationYear;
  }

  const double &Book::price() const
  {
    return m_bookPrice;
  }

  void Book::removeLeadTrailWhiteSpace(std::string &str) const
  {
    int idx1, idx2;
    for (int i = 0; i < str.length(); ++i)
      if (str[i] != ' ')
      {
        idx1 = i;
        break;
      }

    for (int i = str.length() - 1; i >= 0; --i)
      if (str[i] != ' ')
      {
        idx2 = i;
        break;
      }
    str = str.substr(idx1, idx2 - idx1 + 1);
  }

  Book::Book(const std::string &strBook)
  {
    // AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
    int idx1 = strBook.find_first_of(',');
    m_bookAuthor = strBook.substr(0, idx1);
    removeLeadTrailWhiteSpace(m_bookAuthor);

    int idx2 = strBook.find_first_of(',', idx1 + 1);
    m_bookTitle = strBook.substr(idx1 + 1, idx2 - idx1 - 1);
    removeLeadTrailWhiteSpace(m_bookTitle);

    int idx3 = strBook.find_first_of(',', idx2 + 1);
    m_bookPublicationCountry = strBook.substr(idx2 + 1, idx3 - idx2 - 1);
    removeLeadTrailWhiteSpace(m_bookPublicationCountry);

    int idx4 = strBook.find_first_of(',', idx3 + 1);
    std::string price = strBook.substr(idx3 + 1, idx4 - idx3 - 1);
    removeLeadTrailWhiteSpace(price);
    m_bookPrice = std::stod(price);

    int idx5 = strBook.find_first_of(',', idx4 + 1);
    std::string yearUtils = strBook.substr(idx4 + 1, idx5 - idx4 - 1);
    removeLeadTrailWhiteSpace(yearUtils);
    m_bookPublicationYear = static_cast<size_t>(std::stoi(yearUtils));

    m_bookDescription = strBook.substr(idx5 + 1, strBook.length() - idx5 - 1);
    removeLeadTrailWhiteSpace(m_bookDescription);
  }

  const std::string &Book::getBookAuthor() const
  {
    return m_bookAuthor;
  }

  const std::string &Book::getBookDescription() const
  {
    return m_bookDescription;
  }

  std::ostream &operator<<(std::ostream &output, const Book &outputBook)
  {
    output << std::setw(20) << std::right << outputBook.getBookAuthor();
    output << " | ";
    output << std::setw(22) << std::right << outputBook.title();
    output << " | ";
    output << std::setw(5) << std::right << outputBook.country();
    output << " | ";
    output << outputBook.year();
    output << " | ";
    output << std::setw(6) << std::right << std::setprecision(2) << std::fixed << outputBook.price();
    output << " | ";
    output << outputBook.getBookDescription();

    return output;
  }

  Book &Book::operator=(const Book &copyFromBook)
  {
    m_bookAuthor = copyFromBook.getBookAuthor();
    m_bookTitle = copyFromBook.title();
    m_bookPublicationCountry = copyFromBook.country();
    m_bookPublicationYear = copyFromBook.year();
    m_bookPrice = copyFromBook.price();
    m_bookDescription = copyFromBook.getBookDescription();
    return *this;
  }

  void Book::setBookPrice(const double &price)
  {
    m_bookPrice = price;
  }
}