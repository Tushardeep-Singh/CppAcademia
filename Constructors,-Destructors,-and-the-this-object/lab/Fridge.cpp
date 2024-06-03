// Author: Tushardeep Singh
// Seneca College Alumni

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca
{
   // Return food name
   const char *Food::name() const
   {
      return m_name;
   }

   // Return food weight
   int Food::weight() const
   {
      return m_weight;
   }

   // Default contructor
   Food::Food() {}

   // Constructor
   Food::Food(const char *nm, int wei)
   {
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }

   // Default constructor
   Fridge::Fridge()
   {
      m_numFoods = 0;
      m_model = nullptr;
   }

   // Constructor
   Fridge::Fridge(Food farr[], int nf, const char *mod)
   {
      Fridge();
      if (nf > 0 && mod != nullptr && strlen(mod) != 0)
      {
         m_numFoods = nf;
         m_model = new char[strlen(mod) + 1];
         strcpy(m_model, mod);
         for (int i = 0; i < nf && i < FRIDGE_CAP; ++i)
            m_foods[i] = farr[i];
      }
   }

   // Constructor
   Fridge::Fridge(Food farr[], int nf)
   {
      Fridge();
      m_numFoods = nf;
      for (int i = 0; i < nf; ++i)
         m_foods[i] = farr[i];

      m_model = new char[NAME_LEN];
      // Default model of fridge
      strcpy(m_model, "Ice Age");
   }

   // Destructor
   Fridge::~Fridge()
   {
      delete[] m_model;
      m_model = nullptr;
   }

   // Add food to the fridge
   bool Fridge::addFood(const Food &f)
   {
      if (m_numFoods < FRIDGE_CAP)
      {
         m_foods[m_numFoods++] = f;
         return true;
      }
      return false;
   }

   // Change model of the fridge
   void Fridge::changeModel(const char *m)
   {
      if (m != nullptr)
      {
         delete[] m_model;
         m_model = nullptr;
         m_model = new char[strlen(m) + 1];
         strcpy(m_model, m);
      }
   }

   // Return true if the fridge is full.
   bool Fridge::fullFridge() const
   {
      return m_numFoods == FRIDGE_CAP;
   }

   // Return true if fridge contains a food, else false
   bool Fridge::findFood(const char *f) const
   {
      for (int i = 0; i < m_numFoods; ++i)
         if (!strcmp(f, m_foods[i].name()))
            return true;
      return false;
   }

   // Display contents of the fridge
   std::ostream &Fridge::display(std::ostream &os) const
   {
      if (m_model != nullptr)
      {
         std::cout << "Fridge Model: " << m_model << '\n';
         std::cout << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << '\n';
         std::cout << "List of Foods\n";

         if (m_numFoods > 0)
            for (int i = 0; i < m_numFoods; ++i)
            {
               std::cout << std::setw(NAME_LEN) << std::right << m_foods[i].name();
               std::cout << " | ";
               std::cout << m_foods[i].weight() << '\n';
            }
      }
      return os;
   }
}
