#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  int total{0};
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
      bool visLeft = true;
      for (int k = i - 1; k >= 0; k--)
      {
        if (testNum <= treeGrid[k][j])
        {
          visLeft = false;
          break;
        }
      }
      if (visLeft)
      {
        total++;
        continue;
      }
      bool visRight = true;
      for (int k = i + 1; k < treeGrid[i].size(); k++)
      {
        if (testNum <= treeGrid[k][j])
        {
          visRight = false;
          break;
        }
      }
      if (visRight)
      {
        total++;
        continue;
      }
      bool visTop = true;
      for (int k = j - 1; k >= 0; k--)
      {
        if (testNum <= treeGrid[i][k])
        {
          visTop = false;
          break;
        }
      }
      if (visTop)
      {
        total++;
        continue;
      }
      bool visBottom = true;
      for (int k = j + 1; k < treeGrid.size(); k++)
      {
        if (testNum <= treeGrid[i][k])
        {
          visBottom = false;
          break;
        }
      }
      if (visBottom)
      {
        total++;
        continue;
      }
    }
  }
  std::cout << total << std::endl;
  return EXIT_SUCCESS;
}