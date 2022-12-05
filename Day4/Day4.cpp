#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <utility>
std::pair<int, int> getRangeFromString(std::string token)
{
  const char separator = '-';
  size_t hypenPos = token.find(separator);
  std::pair<int, int> pair(std::stoi(token.substr(0, hypenPos)), std::stoi(token.substr(hypenPos + 1)));
  return pair;
}
bool isContained(std::pair<int, int> r1, std::pair<int, int> r2)
{
  if (std::get<0>(r1) == std::get<0>(r2) ||
      std::get<1>(r1) == std::get<1>(r2))
  {
    return true;
  }
  if (std::get<0>(r1) < std::get<0>(r2))
  {
    return std::get<1>(r1) >= std::get<1>(r2);
  }
  return std::get<1>(r1) <= std::get<1>(r2);
}
int main()
{
  std::ifstream inputFile;
  std::string currentLine;
  std::string firstRange;
  std::string secondRange;
  const char separator = ',';
  inputFile.open("Day4.txt");
  int count{0};
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);

    size_t commaIndex = currentLine.find(separator);
    firstRange = currentLine.substr(0, commaIndex);
    secondRange = currentLine.substr(commaIndex + 1);

    auto firstResult = getRangeFromString(firstRange);
    auto secondResult = getRangeFromString(secondRange);

    if (isContained(firstResult, secondResult))
    {
      count++;
    }
  }
  std::cout << count << std::endl;
  return 0;
}