#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
int main()
{
  std::ifstream inputFile;
  std::string currentLine1;
  std::string currentLine2;
  std::string currentLine3;
  inputFile.open("Day3.txt");
  int length{0};
  int amount{0};
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine1);
    std::getline(inputFile, currentLine2);
    std::getline(inputFile, currentLine3);
    std::set<char> firstSet(currentLine1.begin(), currentLine1.end());
    std::set<char> secondSet(currentLine2.begin(), currentLine2.end());
    std::set<char> thirdSet(currentLine3.begin(), currentLine3.end());
    std::set<char> intersect;
    std::set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(),
                          std::inserter(intersect, intersect.begin()));
    std::set<char> firstIntersectCopy(intersect);
    std::set<char> lastIntersect;
    std::set_intersection(firstIntersectCopy.begin(), firstIntersectCopy.end(), thirdSet.begin(), thirdSet.end(),
                          std::inserter(lastIntersect, lastIntersect.begin()));
    for (auto itr : lastIntersect)
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