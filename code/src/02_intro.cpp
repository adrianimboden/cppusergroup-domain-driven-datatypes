#include <cassert>
#include <iostream>
#include <string>

class X {
  int value_;

public:
  explicit X(int value) : value_{value} {
    if ((value_ < 1) or (value_ > 3))
      throw std::out_of_range{
        "value not in domain",
      };
  }

  operator int() const { return value_; }
};

#if FOO
class X {
public:
  explicit X(int value);
  operator int() const;
};
#endif

using Y = char;
Y foo(X input) {
  switch (input) {
  case 1: return 'D';
  case 2: return 'B';
  case 3: return 'A';
  }
  assert(false); // unreachable
}

int main() {
  const auto value = X{5}; // throws
  foo(value);
}
