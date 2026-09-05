#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {

// TODO: add your solution here
  std::string reverse_string(std::string s) {
    std::reverse(s.begin(), s.end());
    return s;
  }
}  // namespace reverse_string
