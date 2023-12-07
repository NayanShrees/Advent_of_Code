#include "days/day_2.hpp"

#include <iostream>

#include "util.hpp"

namespace day_2 {

void Solve() {
  std::string file = util::ReadFile(2);
  Part1(file);
  Part2(file);
}

void Part1(std::string file) {
  const int MAX_RED = 12;
  const int MAX_GREEN = 13;
  const int MAX_BLUE = 14;
  int total = 0;

  for (auto& line : util::Split(file)) {
    try {
      int red = GetColour(line, std::regex("(\\d+) red"), MAX_RED);
      int green = GetColour(line, std::regex("(\\d+) green"), MAX_GREEN);
      int blue = GetColour(line, std::regex("(\\d+) blue"), MAX_BLUE);
      std::smatch smatch;
      std::regex_search(line, smatch, std::regex("Game (\\d+)"));
      total += std::stoi(smatch[1]);
    } catch (const std::runtime_error& err) {
    }
  }
  std::cout << "Day 2 - Part 1: " << total << std::endl;
}

void Part2(std::string file) {
  int total = 0;
  for (auto& line : util::Split(file)) {
    int red = GetMaxColour(line, std::regex("(\\d+) red"));
    int green = GetMaxColour(line, std::regex("(\\d+) green"));
    int blue = GetMaxColour(line, std::regex("(\\d+) blue"));
    total += red * green * blue;
  }
  std::cout << "Day 2 - Part 2: " << total << std::endl;
}

int GetColour(std::string line, std::regex regex, int max) {
  std::smatch smatch;
  int total = 0;
  while (std::regex_search(line, smatch, regex)) {
    if (std::stoi(smatch[0]) > max)
      throw std::runtime_error("Total already greater than max!");

    total += std::stoi(smatch[0]);
    line = smatch.suffix();
  }
  return total;
}

int GetMaxColour(std::string line, std::regex regex) {
  std::smatch smatch;
  int total = 0;
  while (std::regex_search(line, smatch, regex)) {
    if (total < std::stoi(smatch[0])) total = std::stoi(smatch[0]);
    line = smatch.suffix();
  }
  return total;
}

}  // namespace day_2