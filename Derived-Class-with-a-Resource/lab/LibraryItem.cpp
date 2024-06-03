// Author: Tushardeep Singh
// Seneca College Alumni

#include "./LibraryItem.h"

namespace seneca
{
  LibraryItem::LibraryItem()
  {
    m_title = nullptr;
    m_year = 0;
  }

  LibraryItem::LibraryItem(const char *title, int year)
  {
    setTitle(title);
    setYear(year);
  }

  char *LibraryItem::getTitle() const
  {
    return m_title;
  }

  int LibraryItem::getYear() const
  {
    return m_year;
  }

  void LibraryItem::setTitle(const char *title)
  {
    if (m_title != nullptr)
    {
      delete[] m_title;
      m_title = nullptr;
    }
    m_title = new char[std::strlen(title) + 1];
    std::strcpy(m_title, title);
  }

  void LibraryItem::setYear(int year)
  {
    m_year = year;
  }

  LibraryItem::LibraryItem(const LibraryItem &other)
  {
    this->setTitle(other.getTitle());
    this->setYear(other.getYear());
  }

  LibraryItem &LibraryItem::operator=(const LibraryItem &other)
  {
    this->setTitle(other.getTitle());
    this->setYear(other.getYear());
    return *this;
  }

  LibraryItem::~LibraryItem()
  {
    if (this->m_title != nullptr)
    {
      delete[] this->m_title;
      this->m_title = nullptr;
    }
    this->m_year = 0;
  }

  std::ostream &LibraryItem::display(std::ostream &ostr) const
  {
    ostr << "Title: " << m_title << " (" << m_year << ')';
    return ostr;
  }
}