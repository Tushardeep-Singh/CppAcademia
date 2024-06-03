// Author: Tushardeep Singh
// Seneca College Alumni

#include "StMark.h"

namespace seneca
{
  bool printReport(const char *filename)
  {
    // open the data file for reading
    std::FILE *dataFile = nullptr;
    dataFile = std::fopen(filename, "r");
    if (!dataFile)
      return 0;

    // To get correct frequency of marks
    std::unordered_map<std::string, int> nameMarks;

    // To maintain exact order of names as in dataFile
    std::map<int, std::vector<std::string> > marksName;
    getData(nameMarks, dataFile, marksName);

    // Store the frequency of marks
    int marksFreq[10] = {0};
    fillMarks(marksFreq, nameMarks);

    printGraph(marksFreq, 10, "Students' mark distribution");

    printIndividualMarks(marksName);

    // close file, avoid memory leak
    std::fclose(dataFile);
    dataFile = nullptr;
    return true;
  }

  void getData(std::unordered_map<std::string, int> &nameMarks, std::FILE *dataFile, std::map<int, std::vector<std::string> > &marksName)
  {
    char line[100];
    std::string str;
    int marks;
    while (fgets(line, sizeof(line), dataFile))
    {
      // Parse the stream into tokens
      str = strtok(line, ",");
      str += " ";
      str += strtok(nullptr, ",");
      marks = stoi(strtok(nullptr, ""));
      nameMarks[str] = marks;
      marksName[marks].push_back(str);
    }
  }

  // Calculate the frequency of marks
  void fillMarks(int (&marksFreq)[10], std::unordered_map<std::string, int> &nameMarks)
  {
    std::unordered_map<std::string, int>::iterator it;
    for (it = nameMarks.begin(); it != nameMarks.end(); ++it)
    {
      int marks = it->second;
      if (marks >= 91 && marks <= 100)
        marksFreq[0]++;
      if (marks >= 81 && marks <= 90)
        marksFreq[1]++;
      if (marks >= 71 && marks <= 80)
        marksFreq[2]++;
      if (marks >= 61 && marks <= 70)
        marksFreq[3]++;
      if (marks >= 51 && marks <= 60)
        marksFreq[4]++;
      if (marks >= 41 && marks <= 50)
        marksFreq[5]++;
      if (marks >= 31 && marks <= 40)
        marksFreq[6]++;
      if (marks >= 21 && marks <= 30)
        marksFreq[7]++;
      if (marks >= 11 && marks <= 20)
        marksFreq[8]++;
      if (marks <= 10)
        marksFreq[9]++;
    }
  }

  void printIndividualMarks(std::map<int, vector<std::string> > &marksName)
  {
    std::map<int, vector<std::string> >::reverse_iterator itr;
    int count = 1;

    for (itr = marksName.rbegin(); itr != marksName.rend(); ++itr)
    {
      for (size_t i = 0;i < itr->second.size(); ++i)
      {
        std::cout << std::setw(3) << std::left << count++;
        std::cout << ": [";
        std::cout << std::setw(3) << std::left << itr->first;
        std::cout << "] " << itr->second[i] << '\n';
      }
    }
    std::cout << "----------------------------------------\n";
  }
}