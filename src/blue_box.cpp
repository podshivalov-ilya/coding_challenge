#include "blue_box.hpp"
#include <algorithm>

double BlueBox::cantor(double x, double y) {
    return 0.5 * (x + y) * (x + y + 1.0) + y;
}

BlueBox::BlueBox(double initial_weight)
    : Box(initial_weight),
    min_weight_(initial_weight),
    max_weight_(initial_weight) {}

void BlueBox::absorb(double token_weight) {
    min_weight_ = std::min(min_weight_, token_weight);
    max_weight_ = std::max(max_weight_, token_weight);
    weight_ = BlueBox::cantor(min_weight_, max_weight_);
}

