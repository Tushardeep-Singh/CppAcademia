// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <string>
#include <stdexcept>

namespace seneca
{
  // Templated class
  template <typename T>
  class Collection
  {
  private:
    std::string m_nameOfCollection;
    T *m_collectionArray{nullptr};
    size_t m_numItemsInCollectionArr;
    // Declaring the observer
    void (*m_observer)(const Collection<T> &, const T &){nullptr};

  public:
    // 1-arg Constructor
    Collection(const std::string &name);
    // Deleting the copy constructor
    Collection(const Collection &) = delete;
    // Deleting the copy assignment operator
    Collection &operator=(const Collection &) = delete;
    // Destructor
    ~Collection();
    // Getter: returns the name of the collection
    const std::string &name() const;
    // Getter: returns the size of the collection
    size_t size() const;
    // Setter: sets the size of the collection (m_numItemsInCollectionArr) to param size
    void setSize(const int &size);
    // Setter: sets the observer variable to param "observer"
    void setObserver(void (*observer)(const Collection<T> &, const T &));
    // Overloading the operator '+='
    Collection<T> &operator+=(const T &item);
    // Overloading the subscripting operator
    T &operator[](size_t idx) const;
    T *operator[](const std::string &title) const;
  };

  template <typename T>
  void Collection<T>::setSize(const int &size)
  {
    m_numItemsInCollectionArr = size;
  }

  template <typename T>
  Collection<T>::Collection(const std::string &name)
  {
    m_observer = nullptr;
    m_nameOfCollection = name;
    m_collectionArray = nullptr;
    m_numItemsInCollectionArr = 0;
  }

  template <typename T>
  Collection<T>::~Collection()
  {
    m_nameOfCollection = "";
    if (m_collectionArray != nullptr)
    {
      delete[] m_collectionArray;
      m_collectionArray = nullptr;
    }
    m_numItemsInCollectionArr = 0;
  }

  template <typename T>
  const std::string &Collection<T>::name() const
  {
    return m_nameOfCollection;
  }

  template <typename T>
  size_t Collection<T>::size() const
  {
    return m_numItemsInCollectionArr;
  }

  template <typename T>
  void Collection<T>::setObserver(void (*observer)(const Collection<T> &, const T &))
  {
    m_observer = observer;
  }

  template <typename T>
  Collection<T> &Collection<T>::operator+=(const T &item)
  {
    for (int i = 0; i < size(); ++i)
      if (m_collectionArray[i].title() == item.title())
        return *this;

    if (size() == 0)
    {
      m_collectionArray = new T[size() + 1];
      m_collectionArray[size()] = item;
      if (m_observer)
        m_observer(*this, m_collectionArray[size()]);
      setSize(size() + 1);

      return *this;
    }

    T *tempArr = new T[size() + 1];
    for (int i = 0; i < size(); ++i)
      tempArr[i] = m_collectionArray[i];
    tempArr[size()] = item;

    delete[] m_collectionArray;
    m_collectionArray = nullptr;

    m_collectionArray = new T[size() + 1];
    setSize(size() + 1);
    for (int i = 0; i < size(); ++i)
      m_collectionArray[i] = tempArr[i];

    delete[] tempArr;
    tempArr = nullptr;

    if (m_observer)
      m_observer(*this, m_collectionArray[size() - 1]);

    return *this;
  }

  template <typename T>
  T &Collection<T>::operator[](size_t idx) const
  {
    if (idx < 0 || idx >= size())
      throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");

    return m_collectionArray[idx];
  }

  template <typename T>
  T *Collection<T>::operator[](const std::string &title) const
  {
    for (int i = 0; i < size(); ++i)
      if (m_collectionArray[i].title() == title)
        return &m_collectionArray[i];
    return nullptr;
  }

  template <typename T>
  std::ostream &operator<<(std::ostream &output, const Collection<T> &outputCollection)
  {
    for (int i = 0; i < outputCollection.size(); ++i)
      output << outputCollection[i];
    return output;
  }
}

#endif