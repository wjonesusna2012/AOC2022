#include <iostream>
#include <fstream>
#include <functional>
#include <vector>

std::function<int(int)> createDivisibleBy(int divisor, int trueMonkey, int falseMonkey)
{
  return [divisor, trueMonkey, falseMonkey](int a) -> int
  {
    return a % divisor == 0 ? trueMonkey : falseMonkey;
  };
}
class Monkey
{
public:
  int itemsProcessed{0};
  std::vector<int> heldItems;
  std::function<int(int)> operationFunction;
  std::function<int(int)> testFunction;

  Monkey(std::vector<int> sI, std::function<int(int)> oF, std::function<int(int)> tF)
  {
    heldItems = sI;
    operationFunction = oF;
    testFunction = tF;
  }
  void addItem(int item)
  {
    heldItems.push_back(item);
  }
  std::vector<std::pair<int, int>> processItems()
  {
    std::vector<std::pair<int, int>> redistributedItems;
    for (auto i : heldItems)
    {
      int adjusted = operationFunction(i);
      // Divide by 3 after monkey doesn't break it. Floor is applied by default for int division
      adjusted /= 3;
      int toMonkey = testFunction(adjusted);
      redistributedItems.emplace_back(toMonkey, adjusted);
    }
    return redistributedItems;
  }
};

int main(int argc, char *argv[])
{
  std::vector<Monkey> monkeyList;
  // MOnkey 0
  monkeyList.emplace_back(
      std::vector<int>{80}, [](int a) -> int
      { return a * 5; },
      createDivisibleBy(2, 4, 3));
  // Monkey 1
  monkeyList.emplace_back(
      std::vector<int>{75, 83, 74}, [](int a) -> int
      { return a + 7; },
      createDivisibleBy(7, 5, 6));
  return EXIT_SUCCESS;
}