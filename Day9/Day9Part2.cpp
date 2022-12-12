#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

std::pair<int, int> operator+(const std::pair<int, int> &x, const std::pair<int, int> &y)
{
  return std::make_pair(x.first + y.first, x.second + y.second);
}
const std::pair<int, int> UP = std::make_pair<int, int>(0, 1);
const std::pair<int, int> DOWN = std::make_pair<int, int>(0, -1);
const std::pair<int, int> LEFT = std::make_pair<int, int>(-1, 0);
const std::pair<int, int> RIGHT = std::make_pair<int, int>(1, 0);

bool testDragDistance(std::pair<int, int> leader, std::pair<int, int> next)
{
  return (std::abs(leader.first - next.first) > 1 || std::abs(leader.second - next.second) > 1);
}

int main(int argc, char *argv[])
{
  char direction{' '};
  int spaces{0};
  std::vector<std::pair<int, int>> ropePieces(10);
  std::set<std::pair<int, int>> visitedSpaces;
  std::ifstream inputFile;
  inputFile.open(argv[1]);

  visitedSpaces.emplace(ropePieces[9]);
  while (inputFile.good())
  {
    inputFile >> direction >> spaces;
    for (int i = 0; i < spaces; i++)
    {
      switch (direction)
      {
      case 'D':
        ropePieces[0] = ropePieces[0] + DOWN;
        break;
      case 'U':
        ropePieces[0] = ropePieces[0] + UP;
        break;
      case 'L':
        ropePieces[0] = ropePieces[0] + LEFT;
        break;
      case 'R':
        ropePieces[0] = ropePieces[0] + RIGHT;
        break;
      }
      for (auto i = 0; i < ropePieces.size() - 1; i++)
      {
        auto head = ropePieces[i];
        auto tail = ropePieces[i + 1];
        if (testDragDistance(head, tail))
        {
          if (std::abs(tail.first - head.first) > 1)
          {
            tail.first = (head.first + tail.first) >> 1;
          }
          else
          {
            tail.first = head.first;
          }
          if (std::abs(tail.second - head.second) > 1)
          {
            tail.second = (head.second + tail.second) >> 1;
          }
          else
          {
            tail.second = head.second;
          }
          ropePieces[i + 1] = tail;
        }
      }
      visitedSpaces.emplace(ropePieces[9]);
      std::cout << ropePieces[9].first << ' ' << ropePieces[9].second << std::endl;
    }
  }
  std::cout << visitedSpaces.size() << std::endl;
  return EXIT_SUCCESS;
}