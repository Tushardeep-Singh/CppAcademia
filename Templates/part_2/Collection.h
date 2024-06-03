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
    static T m_dummyObject;

  protected:
    // Returns true if param 'item' is present in m_collectionOfT else false
    // Inline to help compiler distinguish between specialised and normal definition
    inline bool lookItem(const T &item) const;

  public:
    Collection(){};
    // Getter: returns m_itemsInCollection
    int size();
    // Outputs the content of array m_collectionOfT
    void display(std::ostream &output = std::cout);
    // Stores a new item in m_collectionOfT if space is available
    virtual bool add(const T &item);
    // Returns the element stored at m_collectionOfT[index]
    T operator[](const int &index) const;
    // Destructor
    virtual ~Collection(){};
  };

  template <typename T, size_t CAPACITY>
  T Collection<T, CAPACITY>::m_dummyObject{};

  template <>
  Pair Collection<Pair, 100>::m_dummyObject{"No Key", "No Value"};

  template <typename T, size_t CAPACITY>
  bool Collection<T, CAPACITY>::lookItem(const T &item) const
  {
    for (int i = 0; i < m_itemsInCollection; ++i)
      if (item == m_collectionOfT[i])
        return true;
    return false;
  }

  template <>
  bool Collection<double, 100>::lookItem(const double &item) const
  {
    for (int i = 0; i < m_itemsInCollection; ++i)
      if (std::abs(m_collectionOfT[i] - item) <= 0.01)
        return true;
    return false;
  }

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
}
#endif