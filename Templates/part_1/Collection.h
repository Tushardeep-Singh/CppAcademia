// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "Pair.h"

namespace seneca
{
  // Template class Collection
  template <typename T, size_t CAPACITY = 0>
  class Collection
  {
  private:
    // Array of type T
    T m_collectionOfT[CAPACITY]{};
    // Stores number of items in array m_collectionOfT
    int m_itemsInCollection{0};
    // Dummy object
    T m_dummyObject{};

  public:
    // Getter: returns m_itemsInCollection
    int size();
    // Outputs the content of array m_collectionOfT
    void display(std::ostream &output = std::cout);
    // Stores a new item in m_collectionOfT if space is available
    bool add(const T &item);
    // Returns the element stored at m_collectionOfT[index]
    T operator[](const int &index) const;
  };

  template <typename T, size_t CAPACITY>
  int Collection<T, CAPACITY>::size()
  {
    return m_itemsInCollection;
  }

  template <typename T, size_t CAPACITY>
  void Collection<T, CAPACITY>::display(std::ostream &output)
  {
    output << "----------------------\n";
    output << "| Collection Content |\n";
    output << "----------------------\n";

    for (int i = 0; i < m_itemsInCollection; ++i)
      output << m_collectionOfT[i] << '\n';

    output << "----------------------\n";
  }

  template <typename T, size_t CAPACITY>
  bool Collection<T, CAPACITY>::add(const T &item)
  {
    if (m_itemsInCollection < CAPACITY)
      m_collectionOfT[m_itemsInCollection++] = item;
    return m_itemsInCollection < CAPACITY;
  }

  template <typename T, size_t CAPACITY>
  T Collection<T, CAPACITY>::operator[](const int &index) const
  {
    if (index >= 0 && index <= m_itemsInCollection)
      return m_collectionOfT[index];
    return m_dummyObject;
  }

  template <>
  class Collection<seneca::Pair, 100>
  {
    seneca::Pair m_dummyObject{"No Key", "No Value"};
  };
}

#endif