// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Book.h"

namespace seneca
{
  Book::Book()
  {
    m_author = nullptr;
  }

  Book::Book(const char *title, int year, const char *author) : LibraryItem(title, year)
  {
    setAuthor(author);
  }

  Book::~Book()
  {
    LibraryItem::~LibraryItem();
    if (m_author != nullptr)
    {
      delete[] m_author;
      m_author = nullptr;
    }
  }

  char *Book::getAuthor() const
  {
    return m_author;
  }

  void Book::setAuthor(const char *author)
  {
    if (m_author != nullptr)
    {
      delete[] m_author;
      m_author = nullptr;
    }
    m_author = new char[std::strlen(author) + 1];
    std::strcpy(m_author, author);
  }

  Book::Book(const Book &otherBook) : LibraryItem(otherBook.getTitle(), otherBook.getYear())
  {
    this->setAuthor(otherBook.getAuthor());
  }

  Book &Book::operator=(const Book &otherBook)
  {
    this->setAuthor(otherBook.getAuthor());
    LibraryItem::setTitle(otherBook.getTitle());
    LibraryItem::setYear(otherBook.getYear());

    return *this;
  }

  std::ostream &Book::display(std::ostream &ostr) const
  {
    LibraryItem::display(ostr);
    ostr << "\nAuthor: " << m_author;
    return ostr;
  }

  bool Book::operator>(const Book &other) const
  {
    if (!this->getAuthor() || !other.getAuthor())
      return false;
    return std::strcmp(this->getAuthor(), other.getAuthor()) > 0;
  }
}
