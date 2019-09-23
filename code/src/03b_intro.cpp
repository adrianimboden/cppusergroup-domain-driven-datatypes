#include <array>

class DieRoll {
  int value_;

public:
  explicit DieRoll(int value) : value_{value} {
    if (value < 1 or value > 6)
      throw std::invalid_argument{"invalid roll"};
  }
  operator int() { return value_; }
};

DieRoll roll_dice() {
  //...
  return DieRoll{7};
}

int yazzee_count(std::array<DieRoll, 5> dies) {
  //...
  return 5;
}

int main() { //
  yazzee_count({
    roll_dice(),
    roll_dice(),
    roll_dice(),
    roll_dice(),
    roll_dice(),
  });
}
