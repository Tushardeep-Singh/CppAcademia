// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_SPELL_CHECKER_H
#define SENECA_SPELL_CHECKER_H

#include <string>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <iostream>

namespace seneca
{
  const int LENGTH_OF_BAD_GOOD_WORDS_ARRAY = 6;
  class SpellChecker
  {
  private:
    // Array storing bad words
    std::string m_badWords[LENGTH_OF_BAD_GOOD_WORDS_ARRAY];
    // Array storing good words
    std::string m_goodWords[LENGTH_OF_BAD_GOOD_WORDS_ARRAY];
    // Integer storing num of words present in m_badWords & m_goodWords
    int m_numOfWords{0};
    // Unordered_map to store number of times each bad word has been replace with good word
    std::unordered_map<std::string, int> m_badWordsCount;

  public:
    // 1-arg constructor
    SpellChecker(const char *filename);
    // Sets the badWord at index idx in array m_badWords to param "badWord"
    void setBadWordsArr(const int &idx, const std::string &badWord);
    // Sets the goodWord at index idx in array m_goodWords to param "goodWord"
    void setGoodWordsArr(const int &idx, const std::string &goodWord);
    // Increments the m_numOfWords by 1
    void incrementNumOfWords();
    // Replaces the bad words in param "text" by good words
    void operator()(std::string &text);
    // Getter: returns the m_badWords & m_goodWords array size i.e. m_numOfWords
    int getArrSize() const;
    // Returns the badWord at index idx in array m_badWords
    const std::string &getBadWordFromArr(int &idx) const;
    // Returns the goodWord at index idx in array m_goodWords
    const std::string &getGoodWordFromArr(const int &idx) const;
    // Displays the statistics of replacements of bad words with good words
    void showStatistics(std::ostream &out);
  };
}

#endif