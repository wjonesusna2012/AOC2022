#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <deque>
#include <regex>
#include <map>
int main()
{
  int total{0};
  std::ifstream inputFile;
  std::string currentLine;
  inputFile.open("Day7.txt");
  std::deque<std::string> directoryStack;
  std::map<std::string, int> allElements;
  std::regex spaceRegex(" ");
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);
    if (currentLine.find("$ cd") == 0) // Starts with $
    {
      std::string proposedTarget = currentLine.substr(5);
      if (proposedTarget == "..")
      {
        directoryStack.pop_back();
      }
      else
      {
        if (allElements.find(proposedTarget) != allElements.end())
        {
          directoryStack.push_back(proposedTarget);
        }
        else
        {
          directoryStack.push_back(proposedTarget);
          allElements[proposedTarget] = 0;
        }
      }
    }
    else if (currentLine.find("$ ls") == 0)
    {
      // Do nothing
    }
    else
    {
      std::sregex_token_iterator itr(currentLine.begin(), currentLine.end(), spaceRegex, -1);
      if (*itr == "dir")
      {
        // Do nothing
      }
      else
      {
        for (auto it = directoryStack.begin(); it != directoryStack.end(); it++)
        {
          allElements[*it] += std::stoi(*itr);
        }
      }
    }
  }
  for (auto j = allElements.begin(); j != allElements.end(); j++)
  {
    if (j->second <= 100000)
    {
      total += j->second;
    }
  }
  std::cout << total << std::endl;
  return EXIT_SUCCESS;
}