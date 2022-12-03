#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

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

auto createP2Map(char rock, char paper, char scissors)
{
  std::map<char, char> result = {
      {rock, 'R'},
      {paper, 'P'},
      {scissors, 'S'}};
  return result;
};

int getResultFromBattle(char p1, char p2)
{
  int choiceVal = p2ChoiceValues[p2];
  if (p1 == p2)
    return DRAW + choiceVal;
  if (p1 == 'R')
  {
    return p2 == 'P' ? WIN + choiceVal : LOSS + choiceVal;
  }
  if (p1 == 'P')
  {
    return p2 == 'S' ? WIN + choiceVal : LOSS + choiceVal;
  }
  if (p1 == 'S')
  {
    return p2 == 'R' ? WIN + choiceVal : LOSS + choiceVal;
  }
  return 100000;
}
int main()
{
  std::ifstream inputFile;
  std::string currentLine;
  inputFile.open("Day2.txt");
  auto p2Choices = createP2Map('X', 'Y', 'Z');
  int points{0};
  while (inputFile.good())
  {
    std::getline(inputFile, currentLine);
    points += getResultFromBattle(p1Choices[currentLine.at(0)], p2Choices[currentLine.at(2)]);
  }
  std::cout << "Total Points: " << points << std::endl;
  return 0;
}