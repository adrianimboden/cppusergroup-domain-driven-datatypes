#include <cassert>
#include <iostream>
#include <string>

template <typename T, T from, T to>
class Number {
  T value_;

public:
  static_assert(from <= to);
  explicit Number(T value)
    : value_{value} {
    if (!((value_ >= from) && (value_ <= to))) {
      throw std::out_of_range("value not in domain");
    }
  }

  operator T() const { return value_; }
};

int main() {
  const auto a = Number<int, 2, 5>{3};
  const auto b = Number<int, 1, 2>{2};

  const auto c = Number<int, 4, 5>{a}; //-> runtime error
  const auto d = Number<int, 1, 2>{8}; //-> runtime error
  const auto e = Number<int, 1, 5>{a}; //-> implicit conversion
}
