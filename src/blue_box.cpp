#include "blue_box.hpp"
#include <algorithm>

int BlueBox::cantor(int x, int y) {
    return ((x + y) * (x + y + 1) / 2) + y;
}

double BlueBox::cantord(double x, double y) {
    return BlueBox::cantor(std::floor(x), std::floor(y));
}

BlueBox::BlueBox(double initial_weight)
    : Box(initial_weight),
    min_weight_(initial_weight),
    max_weight_(initial_weight) {}

void BlueBox::absorb(double token_weight) {
    min_weight_ = std::min(min_weight_, token_weight);
    max_weight_ = std::max(max_weight_, token_weight);
    weight_ = BlueBox::cantord(min_weight_, max_weight_);
}

