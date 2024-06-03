// Author: Tushardeep Singh
// Seneca College Alumni

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>
#include <iomanip>

namespace seneca
{

   const int MAT_LEN = 10;

   class GuitarStr
   {
      char m_material[MAT_LEN]{};
      double m_gauge{};

   public:
      // Constructors
      GuitarStr();
      GuitarStr(const char *ma, double ga);
      // Getters
      const char *material() const;
      double gauge() const;
   };

   class Guitar
   {
   private:
      GuitarStr *m_strings;
      int m_numStrings;
      char m_model[15];

   public:
      // Constructors
      Guitar();
      Guitar(const char *mod);
      Guitar(GuitarStr strs[], int ns, const char *mod);
      // Destructor
      ~Guitar();
      // Replaces a GuitarStr in array m_strings
      bool changeString(const GuitarStr &gs, int sn);
      // Restrings the Guitar with a new set of GuitarStr provided through the parameter
      void reString(GuitarStr strs[], int ns);
      // Acts like a destructor
      void deString();
      // Returns true if the Guitar has GuitarStr and false otherwise
      bool strung() const;
      // Returns true if any GuitarStr on the Guitar has a matching gauge value to the provided parameter
      bool matchGauge(double ga) const;
      //  Displays the details of a Guitar to the ostream via the parameter os
      std::ostream &display(std::ostream &os = std::cout) const;
   };
}

#endif
