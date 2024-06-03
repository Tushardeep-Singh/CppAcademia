// Author: Tushardeep Singh
// Seneca College Alumni


/***********************************************************************
OOP244 Workshop # p2: 
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <vector>
#include "./graph.h"

namespace seneca {

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };

   bool printReport(const char* filename);
   void getData(std::unordered_map<std::string, int>& nameMarks, std::FILE *dataFile, std::map<int, std::vector<std::string> > &marksName);
   void fillMarks(int (&marksFreq)[10], std::unordered_map<std::string, int> &nameMarks);
   void printIndividualMarks(std::map<int, vector<std::string> > &marksName);
}
#endif // !SENECA_STMARK_H


