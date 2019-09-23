#include <array>

int roll_dice() {
  //...
  return 8;
}

int yazzee_count(std::array<int, 5> dies) {
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
