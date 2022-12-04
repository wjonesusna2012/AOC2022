#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
int main()
{
  std::ifstream inputFile;
  std::string currentLine;
  inputFile.open("Day3.txt");
  int length{0};
  int amount{0};
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);
    int halfWay = currentLine.length() / 2;
    std::set<char> firstHalfSet(currentLine.begin(), currentLine.begin() + halfWay);
    std::set<char> secondHalfSet(currentLine.begin() + halfWay, currentLine.end());
    std::set<char> intersect;
    std::set_intersection(firstHalfSet.begin(), firstHalfSet.end(), secondHalfSet.begin(), secondHalfSet.end(),
                          std::inserter(intersect, intersect.begin()));
    for (auto itr : intersect)
    {
      if (itr >= 'a')
        amount += itr - 'a' + 1;
      else
        amount += itr - 'A' + 27;
    }
  }
  std::cout << amount << std::endl;
  return 0;
}