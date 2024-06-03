// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Hero.h"

namespace seneca
{
  // Sets the hero to safe empty state
  Hero::Hero()
  {
    std::strcpy(m_heroName, " ");
    m_heroPowers = nullptr;
    m_numPowers = 0;
    m_heroPowerLevel = 0;
  }

  // Overloaded constructor
  Hero::Hero(const char *heroName, Power *heroPowers, int numPowers)
  {
    strcpy(m_heroName, heroName);
    m_numPowers = numPowers;
    m_heroPowers = new Power[m_numPowers];
    for (int i = 0; i < m_numPowers; ++i)
      m_heroPowers[i] = heroPowers[i];

    for (int i = 0; i < m_numPowers; ++i)
      m_heroPowerLevel += m_heroPowers[i].checkRarity();
    m_heroPowerLevel *= m_numPowers;
  }

  // Displays the hero content
  std::ostream &Hero::display(std::ostream &os) const
  {
    os << "Name: " << m_heroName << '\n';
    os << "List of available powers: \n";
    for (int i = 0; i < m_numPowers; ++i)
    {
      os << std::setw(8) << std::right << "Name: ";
      os << m_heroPowers[i].checkName() << ", Rarity: " << m_heroPowers[i].checkRarity() << '\n';
    }
    os << "Power Level: " << m_heroPowerLevel;
    return os;
  }

  void Hero::operator+=(Power &newPower)
  {
    Power *tempPowersStorage = new Power[m_numPowers];
    for (int i = 0; i < m_numPowers; ++i)
      tempPowersStorage[i] = m_heroPowers[i];

    delete[] m_heroPowers;
    m_heroPowers = nullptr;
    m_heroPowers = new Power[m_numPowers + 1];
    for (int i = 0; i < m_numPowers; ++i)
      m_heroPowers[i] = tempPowersStorage[i];
    m_heroPowers[m_numPowers] = newPower;

    delete[] tempPowersStorage;
    tempPowersStorage = nullptr;

    m_heroPowerLevel /= m_numPowers;
    ++m_numPowers;
    m_heroPowerLevel += newPower.checkRarity();
    m_heroPowerLevel *= m_numPowers;
  }

  void Hero::operator-=(int decPower)
  {
    m_heroPowerLevel -= decPower;
  }

  int Hero::getPowerLevel()
  {
    return m_heroPowerLevel;
  }

  bool operator<(Hero &lhsHero, Hero &rhsHero)
  {
    return lhsHero.getPowerLevel() < rhsHero.getPowerLevel();
  }

  bool operator>(Hero &lhsHero, Hero &rhsHero)
  {
    return rhsHero < lhsHero;
  }

  void Hero::setPowerLevel(int power)
  {
    m_heroPowerLevel = power;
  }

  void operator>>(Power &addPower, Hero &rhsHero)
  {
    rhsHero += addPower;
  }

  void operator<<(Hero &lhsHero, Power &addPower)
  {
    lhsHero += addPower;
  }
  
  Hero::~Hero()
  {
    delete[] m_heroPowers;
    m_heroPowers = nullptr;
  }
}