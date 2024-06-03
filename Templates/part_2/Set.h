#ifndef SENECA_SET_H
#define SENECA_SET_H

#include "Collection.h"

namespace seneca
{
  // Template class Set
  template <typename T>
  class Set : public Collection<T, 100>
  {
  public:
    // Default constructor
    Set(){};
    // Destructor
    ~Set(){};
    // Adds item to base class Collection with no duplicates
    bool add(const T &item);
  };

  template <typename T>
  bool Set<T>::add(const T &item)
  {
    if (Collection<T, 100>::lookItem(item))
      return false;
    return Collection<T, 100>::add(item);
  }
}

#endif