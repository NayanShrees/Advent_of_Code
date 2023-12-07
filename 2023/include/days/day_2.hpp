#ifndef DAY_2_H_
#define DAY_2_H_

#include <regex>
#include <string>

namespace day_2 {
void Solve();
void Part1(std::string file);
void Part2(std::string file);
int GetColour(std::string line, std::regex regex, int max);
int GetMaxColour(std::string line, std::regex regex);
}  // namespace day_2

#endif  // DAY_2_H_