// Author: Tushardeep Singh
// Seneca College Alumni

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca
{
   // Getter
   const char *GuitarStr::material() const
   {
      return m_material;
   }

   // Getter
   double GuitarStr::gauge() const
   {
      return m_gauge;
   }

   // Default constructor
   GuitarStr::GuitarStr(){};

   // Constructor
   GuitarStr::GuitarStr(const char *ma, double ga)
   {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

   // Default constructor
   Guitar::Guitar()
   {
      m_strings = nullptr;
      m_numStrings = 0;
   }

   // Constructor
   Guitar::Guitar(const char *mod)
   {
      Guitar();
      strcpy(m_model, mod);
   }

   // Constructor
   Guitar::Guitar(GuitarStr strs[], int ns, const char *mod)
   {
      if (ns != 0 && mod != nullptr)
      {
         strcpy(m_model, mod);
         m_numStrings = ns;
         // Allocate memory
         m_strings = new GuitarStr[m_numStrings];
         for (int i = 0; i < m_numStrings; ++i)
            m_strings[i] = strs[i];
         return;
      }
      Guitar();
   }

   // Destructor
   Guitar::~Guitar()
   {
      delete[] m_strings;
      m_strings = nullptr;
   }

   // Replaces a GuitarStr in array m_strings
   bool Guitar::changeString(const GuitarStr &gs, int sn)
   {
      if (sn < m_numStrings)
         m_strings[sn] = gs;
      return sn < m_numStrings;
   }

   // Restrings the Guitar with a new set of GuitarStr provided through the parameter
   void Guitar::reString(GuitarStr strs[], int ns)
   {
      // Deallocate memory
      delete[] m_strings;
      m_strings = nullptr;

      m_numStrings = ns;
      // Allocate memory
      m_strings = new GuitarStr[m_numStrings];
      for (int i = 0; i < m_numStrings; ++i)
         m_strings[i] = strs[i];
      strcpy(m_model, "Stratocaster");
   }

   // Acts like a destructor
   void Guitar::deString()
   {
      delete[] m_strings;
      m_strings = nullptr;
      m_numStrings = 0;
      strcpy(m_model, "");
   }

   // Returns true if the Guitar has GuitarStr and false otherwise
   bool Guitar::strung() const
   {
      return m_numStrings != 0;
   }

   // Returns true if any GuitarStr on the Guitar has a matching gauge value to the provided parameter
   bool Guitar::matchGauge(double ga) const
   {
      for (int i = 0; i < m_numStrings; ++i)
         if (m_strings[i].gauge() == ga)
            return true;

      return false;
   }

   // Displays the details of a Guitar to the ostream via the parameter os
   std::ostream &Guitar::display(std::ostream &os) const
   {
      if (!strung())
      {
         os << "***Empty Guitar***\n";
         return os;
      }

      os << "Guitar Model: " << m_model << '\n';
      os << "Strings: " << m_numStrings << '\n';
      for (int i = 0; i < m_numStrings; ++i)
      {
         os << "#" << (i + 1);
         os << std::setw(MAT_LEN) << std::right << m_strings[i].material();
         os << " | ";
         os << std::setprecision(1) << std::fixed << m_strings[i].gauge();
         os << '\n';
      }
      return os;
   }
}
