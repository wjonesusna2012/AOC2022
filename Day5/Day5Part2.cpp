#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <regex>
#include <vector>
#include <deque>
#include <stack>

void processMove(std::vector<std::deque<char>> &boxes, int from, int to, int amount)
{
  std::stack<char> temp;
  for (int i = 0; i < amount; i++)
  {
    temp.push(boxes[from - 1].back());
    boxes[from - 1].pop_back();
  }
  for (int i = 0; i < amount; i++)
  {
    boxes[to - 1].push_back(temp.top());
    temp.pop();
  }
}
// inventor lines have at least one box and therefore at least one []
bool isBoxInventory(std::string line)
{
  return line.find('[') != std::string::npos;
}
int main()
{
  std::ifstream inputFile;
  std::string currentLine;
  int numStacks{0};
  inputFile.open("Day5.txt");

  // Get first line and calculate num of stacks based on length. Every box takes 3 chars + blank space except last.
  std::getline(inputFile, currentLine);
  numStacks = (currentLine.length() + 1) / 4;
  std::vector<std::deque<char>> boxes(numStacks);
  while (isBoxInventory(currentLine))
  {
    for (int i = 0; i < numStacks; i++)
    {
      // Grab the middle char, if substring is [A] then A is returned, if it's blank, ' ' is returned.
      char box = currentLine.substr(i * 4, (i * 4) + 3).at(1);
      if (box != ' ')
        boxes[i].push_front(box);
    }
    std::getline(inputFile, currentLine);
  }

  // Burn the empty line
  std::getline(inputFile, currentLine);
  // Process stacks move instructions
  while (inputFile.good())
  {
    int amount{0}, from{0}, to{0};
    std::getline(inputFile, currentLine);

    std::regex numRegex("\\d+");
    auto itr = std::sregex_iterator(currentLine.begin(), currentLine.end(), numRegex);
    amount = std::stoi((*itr++).str());
    from = std::stoi((*itr++).str());
    to = std::stoi((*itr++).str());
    processMove(boxes, from, to, amount);
  }
  for (auto i : boxes)
  {
    std::cout << i.back();
  }
  std::cout << std::endl;
  return 0;
}