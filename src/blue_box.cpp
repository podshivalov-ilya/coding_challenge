#include "blue_box.hpp"
#include <algorithm>

double BlueBox::cantor(double x, double y) {
    return 0.5 * (x + y) * (x + y + 1.0) + y;
}

BlueBox::BlueBox(double initial_weight)
    : Box(initial_weight),
    min_weight_(0.0),
    max_weight_(0.0),
    is_initialized_(false) {}

double BlueBox::absorb(double token_weight) {
    weight_ += token_weight;
    if (!is_initialized_) {
        min_weight_ = token_weight;
        max_weight_ = token_weight;
        is_initialized_ = true;
    }
    min_weight_ = std::min(min_weight_, token_weight);
    max_weight_ = std::max(max_weight_, token_weight);
    return BlueBox::cantor(min_weight_, max_weight_);
}

