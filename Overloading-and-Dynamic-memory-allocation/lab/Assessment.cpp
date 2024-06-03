// Author : Tushardeep Singh
// Seneca College Alumni

#include "./Assessment.h"

namespace seneca
{
  bool read(int &value, FILE *fptr)
  {
    if (fptr != nullptr)
    {
      char data[5];
      if (std::fgets(data, sizeof(data), fptr))
      {
        value = std::stoi(data);
        return true;
      }
    }
    return false;
  }

  bool read(double &value, FILE *fptr)
  {
    if (fptr != nullptr)
    {
      // reset the pointer back to file beginning
      if (std::fseek(fptr, 0, SEEK_SET) != 0)
      {
        std::cerr << "error repositioning the indicator\n";
        return -1;
      }

      char line[60];
      const char *data;
      while (std::fgets(line, sizeof(line), fptr))
      {
        // tokenize the stream with deliminator
        data = strtok(line, ",");
        if (isDouble(data))
        {
          value = std::stod(data);
          return true;
        }
      }
    }
    return false;
  }

  bool isDouble(const char *data)
  {
    // check if the value is a double
    for (size_t i = 0; i < strlen(data); ++i)
      if (data[i] == '.')
        return true;
    return false;
  }

  bool read(char *cstr, FILE *fptr)
  {
    if (fptr != nullptr)
    {
      bool skipFirstLine = true;
      char line[60];
      char *data = nullptr;

      if (std::fseek(fptr, 0, SEEK_SET) != 0)
      {
        std::cerr << "error repositioning the indicator\n";
        return -1;
      }

      while (std::fgets(line, sizeof(line), fptr))
      {
        if (skipFirstLine)
        {
          skipFirstLine = false;
          continue;
        }

        data = strtok(line, ",");
        data = strtok(nullptr, "\n");

        strcpy(cstr, data);
        return true;
      }
    }
    return false;
  }

  int read(Assessment *&aptr, FILE *fptr)
  {
    int realCnt = 0;
    if (fptr != nullptr)
    {
      char line[61];
      std::fgets(line, sizeof(line), fptr);
      int mentionedCnt = std::stoi(strtok(line, "\n"));

      // count number of data lines
      while (std::fgets(line, sizeof(line), fptr))
        ++realCnt;

      if (realCnt != mentionedCnt)
        return 0;

      // allocate dynamic memory to store objects
      aptr = new Assessment[realCnt];

      if (std::fseek(fptr, 0, SEEK_SET) != 0)
      {
        std::cerr << "error repositioning the indicator";
        return -1;
      }

      char *avgMarks = nullptr;
      char *subject = nullptr;
      int idx = 0;
      bool skipFirstLine = true;

      while (std::fgets(line, sizeof(line), fptr))
      {
        if (skipFirstLine)
        {
          skipFirstLine = false;
          continue;
        }
        avgMarks = strtok(line, ",");
        subject = strtok(nullptr, "\n");

        // allocate memory and then value
        aptr[idx].m_mark = new double;
        *aptr[idx].m_mark = std::stod(avgMarks);

        aptr[idx].m_title = new char[strlen(subject) + 1];
        strcpy(aptr[idx++].m_title, subject);

        avgMarks = nullptr;
        subject = nullptr;
      }
    }
    return realCnt;
  }

  // deallocate the memory
  void freeMem(Assessment *&aptr, int size)
  {
    for (int i = 0; i < size; ++i)
    {
      delete aptr[i].m_mark;
      delete[] aptr[i].m_title;

      aptr[i].m_mark = nullptr;
      aptr[i].m_title = nullptr;
    }

    delete[] aptr;
    aptr = nullptr;
  }
}
