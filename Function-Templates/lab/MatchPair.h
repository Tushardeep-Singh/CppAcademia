// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_MATCH_PAIR_H
#define SENECA_MATCH_PAIR_H

#include <utility>

namespace seneca
{
  template <typename T, typename U>
  struct Pair
  {
    T first;
    U second;
  };

  // Adds a Pair element to a dynamic array of Pairs and adding one to its provided size reference
  template <typename T, typename U>
  void addDynamicPairElement(Pair<T, U> *&pArray, const T &first, const U &second, int &size)
  {
    Pair<T, U> *temp = new Pair<T, U>[size + 1];
    for (int k = 0; pArray && k < size; k++)
    {
      temp[k] = pArray[k];
    }
    temp[size].first = first;
    temp[size].second = second;
    delete[] pArray;
    pArray = temp;
    size++;
  }

  // Finds pairs of element that match in two arrays, where the two arrays may carry elements of different types
  template <typename T, typename U>
  Pair<T, U> *matches(const T *arr1, const U *arr2, const int &sizeArr1, const int &sizeArr2, int &returnSize)
  {
    Pair<T, U> *pt = nullptr;
    returnSize = 0;

    for (int i = 0; i < sizeArr1; ++i)
      for (int j = 0; j < sizeArr2; ++j)
        if (arr1[i] == arr2[j])
          addDynamicPairElement(pt, arr1[i], arr2[j], returnSize);

    return pt;
  }

  // Releases the dynamic memory allocated by `matches` function
  template <typename T>
  void releaseMem(T *(&releasePair))
  {
    delete []releasePair;
    releasePair = nullptr;
  }
}

#endif