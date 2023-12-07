#include "days/day_1.hpp"

#include <iostream>
#include <map>
#include <regex>

#include "util.hpp"

namespace day_1 {

void Solve() {
  std::string file = util::ReadFile(1);
  Part1(file);
  Part2(file);
}

void Part1(std::string file) {
  std::regex regex("\\d");
  int total = 0;
  for (auto &line : util::Split(file)) {
    std::smatch smatch;
    std::string number;
    std::regex_search(line, smatch, regex);
    number += smatch[0];
    std::reverse(line.begin(), line.end());
    std::regex_search(line, smatch, regex);
    number += smatch[0];
    total += std::stoi(number);
  }
  std::cout << "Day 1 - Part 1: " << total << std::endl;
}

void Part2(std::string file) {
  std::regex front("one|two|three|four|five|six|seven|eight|nine|\\d");
  std::regex back("eno|owt|eerht|ruof|evif|xis|neves|thgie|enin|\\d");
  int total = 0;
  for (auto &line : util::Split(file)) {
    std::smatch smatch;
    std::string number;
    std::regex_search(line, smatch, front);
    number += MapDigits(smatch[0]);
    std::reverse(line.begin(), line.end());
    std::regex_search(line, smatch, back);
    std::string back = smatch[0];
    std::reverse(back.begin(), back.end());
    number += MapDigits(back);
    total += std::stoi(number);
  }
  std::cout << "Day 1 - Part 2: " << total << std::endl;
}

std::string MapDigits(std::string digit) {
  std::map<std::string, std::string> digits_map{
      {"one", "1"},   {"two", "2"},   {"three", "3"},
      {"four", "4"},  {"five", "5"},  {"six", "6"},
      {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
  return digits_map.find(digit) != digits_map.end() ? digits_map[digit] : digit;
}

}  // namespace day_1