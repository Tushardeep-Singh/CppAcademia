// Author: Tushardeep Singh
// Seneca College Alumni

#include "SpellChecker.h"

namespace seneca
{
  void SpellChecker::setBadWordsArr(const int &idx, const std::string &badWord)
  {
    m_badWords[idx] = badWord;
  }

  void SpellChecker::setGoodWordsArr(const int &idx, const std::string &goodWord)
  {
    m_goodWords[idx] = goodWord;
  }

  void SpellChecker::incrementNumOfWords()
  {
    ++m_numOfWords;
  }

  SpellChecker::SpellChecker(const char *filename)
  {
    std::ifstream file(filename);
    if (!file.is_open())
    {
      throw std::runtime_error("Bad file name!");
    }
    std::string line;
    while (std::getline(file, line))
    {
      int idx1 = line.find_first_of(' ');
      std::string badWord = line.substr(0, idx1);
      setBadWordsArr(m_numOfWords, badWord);

      int idx2 = line.find_first_not_of(' ', idx1);
      std::string goodWord = line.substr(idx2);
      setGoodWordsArr(m_numOfWords, goodWord);
      incrementNumOfWords();
    }
  }

  int SpellChecker::getArrSize() const
  {
    return m_numOfWords;
  }

  const std::string &SpellChecker::getBadWordFromArr(int &idx) const
  {
    return m_badWords[idx];
  }

  const std::string &SpellChecker::getGoodWordFromArr(const int &idx) const
  {
    return m_goodWords[idx];
  }

  void SpellChecker::operator()(std::string &text)
  {
    for (int i = 0; i < getArrSize(); ++i)
    {
      int idx = 0;
      while (text.find(getBadWordFromArr(i), idx) != -1)
      {
        idx = text.find(getBadWordFromArr(i), idx);
        text.replace(idx, getBadWordFromArr(i).length(), getGoodWordFromArr(i));
        m_badWordsCount[getBadWordFromArr(i)]++;
      }
    }
  }

  void SpellChecker::showStatistics(std::ostream &out)
  {
    out << "Spellchecker Statistics\n";
    for (int i = 0; i < getArrSize(); ++i)
    {
      out << std::setw(15) << std::right << getBadWordFromArr(i);
      out << ": ";
      out << m_badWordsCount[getBadWordFromArr(i)];
      out << " replacements\n";
    }
  }
}