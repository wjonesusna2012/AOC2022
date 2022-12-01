#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
  std::ifstream inputFile;
  int tripleSum{0};
  int currSum{0};
  std::string currentLine;
  std::vector<int> calorieCounts = {};

  inputFile.open("Day1.txt");

  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);
    if (currentLine.length() > 0)
    {
      currSum += std::stoi(currentLine);
    }
    else
    {
      calorieCounts.push_back(currSum);
      currSum = 0;
    }
  }
  std::sort(calorieCounts.begin(), calorieCounts.end(), std::greater<int>());
  for (auto i = calorieCounts.begin(); i < calorieCounts.begin() + 3; i++)
  {
    tripleSum += *i;
  }

  std::cout << calorieCounts[0] << std::endl
            << tripleSum << std::endl;

  return 0;
}