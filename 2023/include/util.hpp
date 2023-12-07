#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <vector>

namespace util {

std::string ReadFile(int day, std::string filename);
std::vector<std::string> split(std::string string, char delimiter = '\n');

}  // namespace util

#endif  // UTIL_H_