#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

// Char window plus is OFFSET + 1 since start of window is offset 0 from iterator
const int OFFSET = 13;
int main()
{
  std::ifstream inputFile;
  std::string currentLine;
  inputFile.open("Day6.txt");
  std::getline(inputFile, currentLine);
  auto itr = currentLine.begin();

  while (itr != currentLine.end())
  {
    size_t offset = OFFSET;
    int result{0};
    int prevResult{0};
    while (offset >= 0)
    {
      // Start at the back of the character window to maximize number of advances
      prevResult = result;
      // Works since there are 26 symbols in alphabet, more than 32 results in undefined behavior with bitshift left (<<)
      result |= 1 << *(itr + offset) - 'a';
      // current offset results in repeat character, advance one past repeat since a number with any number of bits set | with one of those bits set is the same.
      if (result == prevResult)
      {
        itr += offset + 1;
        break;
      }
      if (offset == 0)
      {
        std::cout << std::distance(currentLine.begin(), itr) + OFFSET + 1 << std::endl;
        return EXIT_SUCCESS;
      }
      offset--;
    }
  }
  return EXIT_FAILURE;
}