#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

const int LOSS = 0;
const int DRAW = 3;
const int WIN = 6;

std::map<char, char> p1Choices = {
    {'A', 'R'},
    {'B', 'P'},
    {'C', 'S'}};
std::map<char, int> p2ChoiceValues = {
    {'R', 1},
    {'P', 2},
    {'S', 3}};

auto createP2DecisionMap(char win, char lose, char draw)
{
  std::map<char, char> result = {
      {lose, 'L'},
      {draw, 'D'},
      {win, 'W'}};
  return result;
};
// P1 choice => [Lose, Draw, Win]
std::map<char, std::vector<char>> determineChoices = {
    {'P', {'R', 'P', 'S'}},
    {'R', {'S', 'R', 'P'}},
    {'S', {'P', 'S', 'R'}}};
int getResultFromChoice(char p1, char outcome)
{
  if (outcome == 'W')
  {
    return WIN + p2ChoiceValues[determineChoices[p1][2]];
  }
  if (outcome == 'D')
  {
    return DRAW + p2ChoiceValues[determineChoices[p1][1]];
  }
  if (outcome == 'L')
  {
    return LOSS + p2ChoiceValues[determineChoices[p1][0]];
  }
  return -200000;
}
int main()
{
  std::ifstream inputFile;
  std::string currentLine;
  inputFile.open("Day2.txt");
  auto p2Choices = createP2DecisionMap('Z', 'X', 'Y');
  int points{0};
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);
    points += getResultFromChoice(p1Choices[currentLine.at(0)], p2Choices[currentLine.at(2)]);
  }
  std::cout << "Total Points: " << points << std::endl;
  return 0;
}