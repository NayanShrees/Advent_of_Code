#include "util.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <streambuf>

namespace util {

std::string ReadFile(int day, std::string filename /* = ""*/) {
  std::string filepath = "data/day_" + std::to_string(day) + "/";
  filepath.append(filename.empty() ? "day_" + std::to_string(day) + ".txt"
                                   : filename);

  std::ifstream file(filepath);
  if (!file.is_open()) throw std::runtime_error(filename + " not found!");
  return std::string((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
}

std::vector<std::string> Split(std::string string, char delimiter /* = '\n'*/) {
  std::vector<std::string> result;
  std::stringstream ss(string);
  std::string item;

  while (getline(ss, item, delimiter)) {
    result.push_back(item);
  }

  return result;
}

}  // namespace util