#include <cassert>
#include <iostream>
#include <string>

template <typename T, T from, T to>
class Number {
  T value_;

public:
  static_assert(from <= to);
  constexpr explicit Number(T value) : value_{value} {
    if (!((value_ >= from) && (value_ <= to))) {
      throw std::out_of_range("value not in domain");
    }
  }

  template <T other_from, T other_to>
  /*implicit */ constexpr Number(Number<T, other_from, other_to> other)
    : value_{T{other}} {
    static_assert(other_from >= from, "value not in domain");
    static_assert(other_from <= to, "value not in domain");
    static_assert(other_to <= to, "value not in domain");
    static_assert(other_to >= from, "value not in domain");
  }

  constexpr operator T() const { return value_; }
};

template <typename T, T lhs_from, T lhs_to, T rhs_from, T rhs_to>
auto operator+(Number<T, lhs_from, lhs_to> lhs,
               Number<T, rhs_from, rhs_to> rhs) {
  return Number<T, lhs_from + rhs_from, lhs_to + rhs_to>{T{lhs} + T{rhs}};
}

template <typename T, T lhs_from, T lhs_to, T rhs_from, T rhs_to>
auto operator-(Number<T, lhs_from, lhs_to> lhs,
               Number<T, rhs_from, rhs_to> rhs) {
  return Number<T, lhs_from - rhs_to, lhs_to - rhs_from>{T{lhs} + T{rhs}};
}

template <typename T, T lhs_from, T lhs_to, T rhs_from, T rhs_to>
auto operator*(Number<T, lhs_from, lhs_to> lhs,
               Number<T, rhs_from, rhs_to> rhs) {
  return Number<T, lhs_from * rhs_from, lhs_to * rhs_to>{T{lhs} + T{rhs}};
}

template <typename T, T lhs_from, T lhs_to, T rhs_from, T rhs_to>
auto operator/(Number<T, lhs_from, lhs_to> lhs,
               Number<T, rhs_from, rhs_to> rhs) {
  return Number<T, lhs_from / rhs_to, lhs_to / rhs_from>{T{lhs} + T{rhs}};
}

void foo(Number<int, 4, 6>) {}

int main() {
  const auto a = Number<int, 2, 5>{3};
  const auto b = Number<int, 1, 2>{2};

  static_assert(std::is_same_v<decltype(a + b), Number<int, 3, 7>>);
  static_assert(std::is_same_v<decltype(a - b), Number<int, 0, 4>>);
  static_assert(std::is_same_v<decltype(a * b), Number<int, 2, 10>>);
  static_assert(std::is_same_v<decltype(a / b), Number<int, 1, 5>>);

#if FOO
  constexpr auto c = Number<int, 1, 2>{8}; //-> does not compile
#endif
  const auto d = Number<int, 1, 2>{8}; //-> runtime error
#if FOO
  const auto e = Number<int, 4, 5>{a}; //-> static assert
#endif
  const auto f = Number<int, 1, 5>{a}; //-> implicit conversion
}
