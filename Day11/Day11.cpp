#include <iostream>
#include <fstream>
#include <functional>
#include <vector>

std::function<long(long)> createDivisibleBy(long divisor, long trueMonkey, long falseMonkey)
{
  return [divisor, trueMonkey, falseMonkey](long a) -> long
  {
    return a % divisor == 0 ? trueMonkey : falseMonkey;
  };
}
class Monkey
{
public:
  long itemsProcessed{0};
  std::vector<long> heldItems;
  std::function<long(long)> operationFunction;
  std::function<long(long)> testFunction;

  Monkey(std::vector<long> sI, std::function<long(long)> oF, std::function<long(long)> tF)
  {
    heldItems = sI;
    operationFunction = oF;
    testFunction = tF;
  }
  void addItem(long item)
  {
    heldItems.push_back(item);
  }
  std::vector<std::pair<long, long>> processItems()
  {
    std::vector<std::pair<long, long>> redistributedItems;
    for (auto i : heldItems)
    {
      long adjusted = operationFunction(i);
      // Divide by 3 after monkey doesn't break it. Floor is applied by default for long division
      adjusted /= 3;
      long toMonkey = testFunction(adjusted);
      redistributedItems.emplace_back(toMonkey, adjusted % (2 * 7 * 3 * 17 * 11 * 19 * 5 * 13));
    }
    itemsProcessed += heldItems.size();
    return redistributedItems;
  }
  void clearItems()
  {
    heldItems.clear();
  }
};

int main(int argc, char *argv[])
{
  std::vector<Monkey *> monkeyList;
  // MOnkey 0
  monkeyList.emplace_back(
      std::vector<long>{80}, [](long a) -> long
      { return a * 5; },
      createDivisibleBy(2, 4, 3));
  // Monkey 1
  monkeyList.emplace_back(
      std::vector<long>{75, 83, 74}, [](long a) -> long
      { return a + 7; },
      createDivisibleBy(7, 5, 6));
  // Monkey 2
  monkeyList.emplace_back(
      std::vector<long>{86, 67, 61, 96, 52, 63, 73}, [](long a) -> long
      { return a + 5; },
      createDivisibleBy(3, 7, 0));
  // Monkey 3
  monkeyList.emplace_back(
      std::vector<long>{85, 83, 55, 85, 57, 70, 85, 52}, [](long a) -> long
      { return a + 8; },
      createDivisibleBy(17, 1, 5));
  // Monkey 4
  monkeyList.emplace_back(
      std::vector<long>{67, 75, 91, 72, 89}, [](long a) -> long
      { return a + 4; },
      createDivisibleBy(11, 3, 1));
  // Monkey 5
  monkeyList.emplace_back(
      std::vector<long>{66, 64, 68, 92, 68, 77}, [](long a) -> long
      { return a * 2; },
      createDivisibleBy(19, 6, 2));
  // Monkey 6
  monkeyList.emplace_back(
      std::vector<long>{97, 94, 79, 88}, [](long a) -> long
      { return a * a; },
      createDivisibleBy(5, 2, 7));
  // Monkey 7
  monkeyList.emplace_back(
      std::vector<long>{77, 85}, [](long a) -> long
      { return a + 6; },
      createDivisibleBy(13, 4, 0));
  const auto ROUNDS = 20;
  for (long i = 0; i < ROUNDS; i++)
  {
    for (long m = 0; m < monkeyList.size(); m++)
    {
      auto itemsToAdd = monkeyList[m]->processItems();
      monkeyList[m]->clearItems();
      for (auto j : itemsToAdd)
      {
        monkeyList[j.first]->addItem(j.second);
      }
    }
  }
  for (auto x : monkeyList)
  {
    std::cout << x->itemsProcessed << std::endl;
  }
  return EXIT_SUCCESS;
}