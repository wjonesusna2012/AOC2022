#include <iostream>
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
  for (int j = 20; j <= 220; j += 40)
  {
    output += j * cycleValues[j];
    // std::cout << cycleValues[j] << std::endl;
  }
  std::cout << output << std::endl;
  return EXIT_SUCCESS;
}