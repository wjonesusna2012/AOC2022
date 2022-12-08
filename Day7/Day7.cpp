#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <deque>
#include <regex>
#include <map>
// Used name file since directories are files.
enum Types {
  FILE,
  DIRECTORY
};

struct FileStruct {
  Types type;
  int size;
};

int main()
{
  int total{0};
  std::ifstream inputFile;
  std::string currentLine;
  inputFile.open("Day7.txt");
  std::deque<FileStruct> directoryStack;
  std::map<std::string, FileStruct> allElements;
  std::regex spaceRegex(" ");
  while (inputFile.good())
  {
    if(currentLine.find("$ cd") == 0) // Starts with $
    {
      std::string proposedTarget = currentLine.substr(5);
      if(proposedTarget == "..") 
      {
        directoryStack.pop_back();
      }
      else 
      {
        if(allElements.find(proposedTarget) != allElements.end())
        {
          directoryStack.push_back(allElements[proposedTarget]);
        }
        else 
        {
          Types t = DIRECTORY;
          FileStruct elem = {t, 0};
          directoryStack.push_back(elem);
          allElements[proposedTarget] = elem;
        }
      }
    }
    else if(currentLine.find("$ ls") == 0)
    {
      // Do nothing
    }
    else 
    {
      std::sregex_token_iterator itr(currentLine.begin(), currentLine.end(), spaceRegex);
      if(*itr == "dir") 
      {
        // Do nothing
      }
      else 
      {
        for(auto it = directoryStack.begin(); it != directoryStack.end(); it++) {
          it->size += std::stoi(*itr);
        }
      }
    }
    for(auto j = allElements.begin(); j != allElements.end(); j++) {
      std::cout << j->first << ' ' << j->second.size << std::endl; 
      if(j->second.size <= 100000) 
      {
        total += j->second.size;
      }
    } 
  }
  return EXIT_SUCCESS;
}