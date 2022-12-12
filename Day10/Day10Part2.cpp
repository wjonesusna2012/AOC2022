#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char *argv[])
{
  std::ifstream inputFile;
  inputFile.open(argv[1]);

  std::string instruction;
  int value{0};
  int cycle{1};
  int total{1};
  int output{0};
  std::map<int, int> cycleValues;
  while (inputFile.good())
  {
    inputFile >> instruction;
    if (instruction == "noop")
    {
      cycleValues.emplace(cycle, total);
      cycle++;
      continue;
    }
    // instruction is addx
    cycleValues.emplace(cycle, total);
    cycle++;
    cycleValues.emplace(cycle, total);
    cycle++;
    inputFile >> value;
    total += value;
  }
  for (auto i : cycleValues)
  {
    std::cout << (((std::abs((i.first - 1) % 40 - i.second)) <= 1) ? '#' : '.');
    if (i.first % 40 == 0)
      std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}