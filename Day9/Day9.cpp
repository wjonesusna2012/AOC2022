#include <iostream>
#include <fstream>
#include <string>
#include <set>

std::pair<int, int> operator+(const std::pair<int, int> &x, const std::pair<int, int> &y)
{
  return std::make_pair(x.first + y.first, x.second + y.second);
}
const std::pair<int, int> UP = std::make_pair<int, int>(0, 1);
const std::pair<int, int> DOWN = std::make_pair<int, int>(0, -1);
const std::pair<int, int> LEFT = std::make_pair<int, int>(-1, 0);
const std::pair<int, int> RIGHT = std::make_pair<int, int>(1, 0);

bool testDragDistance(std::pair<int, int> head, std::pair<int, int> tail)
{
  return (std::abs(head.first - tail.first) > 1 || std::abs(head.second - tail.second) > 1);
}

int main(int argc, char *argv[])
{
  char direction{' '};
  int spaces{0};
  std::pair<int, int> head(0, 0);
  std::pair<int, int> tail(0, 0);
  std::set<std::pair<int, int>> visitedSpaces;
  std::ifstream inputFile;
  inputFile.open(argv[1]);

  visitedSpaces.emplace(tail);
  while (inputFile.good())
  {
    inputFile >> direction >> spaces;
    for (int i = 0; i < spaces; i++)
    {
      switch (direction)
      {
      case 'D':
        head = head + DOWN;
        break;
      case 'U':
        head = head + UP;
        break;
      case 'L':
        head = head + LEFT;
        break;
      case 'R':
        head = head + RIGHT;
        break;
      }
      if (testDragDistance(head, tail))
      {
        switch (direction)
        {
        case 'D':
          tail = head + UP;
          break;
        case 'U':
          tail = head + DOWN;
          break;
        case 'L':
          tail = head + RIGHT;
          break;
        case 'R':
          tail = head + LEFT;
          break;
        }
        visitedSpaces.emplace(tail);
      }
    }
  }
  for (auto i = visitedSpaces.begin(); i != visitedSpaces.end(); i++)
  {
    std::cout << i->first << ' ' << i->second << std::endl;
  }
  std::cout << visitedSpaces.size() << std::endl;
  return EXIT_SUCCESS;
}