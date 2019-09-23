#include <cassert>
#include <iostream>
#include <string>

using X = int;
using Y = char;

Y foo(X input) {
  switch (input) {
  case 1: return 'D';
  case 2: return 'B';
  case 3: return 'A';
  }
  throw std::out_of_range{
    "value out of domain",
  };
}

int main() {
  const auto value = X{5};
  foo(value); // throws
}
