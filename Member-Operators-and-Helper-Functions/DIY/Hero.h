// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include "./Power.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace seneca
{
  class Hero
  {
  private:
    char m_heroName[MAX_NAME_LENGTH + 1];
    // dynamic array of powers
    Power *m_heroPowers;
    int m_numPowers;
    // power level of a hero
    int m_heroPowerLevel;

  public:
    // Constructors
    Hero();
    Hero(const char *heroName, Power *heroPowers, int numPowers);
    // Destructor
    ~Hero();
    // Displays information of a hero
    std::ostream &display(std::ostream &os = std::cout) const;
    // Operator overloads
    void operator+=(Power &newPower);
    void operator-=(int decPower);
    // Getter
    int getPowerLevel();
    // Setter
    void setPowerLevel(int power);
  };
  // Global logical operator overloads
  bool operator<(Hero &lhsHero, Hero &rhsHero);
  bool operator>(Hero &lhsHero, Hero &rhsHero);
  // Global operator overloads
  void operator>>(Power &addPower, Hero &rhsHero);
  void operator<<(Hero &lhsHero, Power &addPower);
}

#endif