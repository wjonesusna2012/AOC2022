#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  int max{0};
  std::ifstream inputFile;
  std::string currentLine;
  std::vector<std::vector<char>> treeGrid;
  inputFile.open(argv[1]);
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);
    treeGrid.emplace_back(currentLine.begin(), currentLine.end());
  }
  for (int i = 0; i < treeGrid.size(); i++)
  {
    for (int j = 0; j < treeGrid[i].size(); j++)
    {
      // check left
      char testNum = treeGrid[i][j];
      int visLeft{0};
      for (int k = i - 1; k >= 0; k--)
      {
        visLeft++;
        if (testNum <= treeGrid[k][j])
        {
          break;
        }
      }
      int visRight{0};
      for (int k = i + 1; k < treeGrid[i].size(); k++)
      {
        visRight++;
        if (testNum <= treeGrid[k][j])
        {
          break;
        }
      }
      int visTop{0};
      for (int k = j - 1; k >= 0; k--)
      {
        visTop++;
        if (testNum <= treeGrid[i][k])
        {
          break;
        }
      }
      int visBottom{0};
      for (int k = j + 1; k < treeGrid.size(); k++)
      {
        visBottom++;
        if (testNum <= treeGrid[i][k])
        {
          break;
        }
      }
      int score = visBottom * visTop * visLeft * visRight;
      max = score > max ? score : max;
    }
  }
  std::cout << max << std::endl;
  return EXIT_SUCCESS;
}