// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H

#include <cstdio>
#include <iostream>
#include <cstring>
namespace seneca
{
  struct Assessment
  {
    // Average subject mark
    double *m_mark;
    // Subject name
    char *m_title;
  };

  // read function overloads
  bool read(int& value,FILE* fptr);
  bool read(double& value, FILE* fptr);
  bool read(char* cstr, FILE* fptr);
  int read(Assessment*& aptr, FILE* fptr);
  // free Assessment memory
  void freeMem(Assessment*& aptr, int size);
  // check if stream data is double
  bool isDouble(const char *data);
}

#endif