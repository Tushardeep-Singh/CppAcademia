/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>
#include <iomanip>

namespace seneca
{
   const int NAME_LEN = 20;
   const int FRIDGE_CAP = 3;

   class Food
   {
   private:
      // Food name
      char m_name[NAME_LEN];
      // Food weight
      int m_weight;

   public:
      // Constructors
      Food();
      Food(const char *nm, int wei);
      // Getters
      const char *name() const;
      int weight() const;
   };

   class Fridge
   {
   private:
      // Food storage array
      Food m_foods[FRIDGE_CAP];
      // Number of foods present in fridge
      int m_numFoods;
      // Fridge model
      char *m_model;

   public:
      // Constructors
      Fridge();
      Fridge(Food farr[], int nf, const char *mod);
      Fridge(Food farr[], int nf);
      // Destructor
      ~Fridge();
      // Add food to fridge
      bool addFood(const Food &f);
      // Change fridge model
      void changeModel(const char *m);
      // Return true if fridge is full
      bool fullFridge() const;
      // Find food in fridge
      bool findFood(const char *f) const;
      // Display fridge contents
      std::ostream &display(std::ostream &os = std::cout) const;
   };
}

#endif
