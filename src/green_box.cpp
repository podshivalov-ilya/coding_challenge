#include "green_box.hpp"

double GreenBox::mean_square(std::queue<double> tmp_buf) {
    double mean = 0.0;
    double size = tmp_buf.size();
    while (!tmp_buf.empty()) {
        mean += tmp_buf.front();
        tmp_buf.pop();
    }
    mean /= size;
    return mean * mean;
}

GreenBox::GreenBox(double initial_weight)
    : Box(initial_weight),
    token_buf_() {}

double GreenBox::absorb(double token_weight) {
    weight_ += token_weight;
    token_buf_.push(token_weight);
    if (token_buf_.size() > 3) {
        token_buf_.pop();
    }
    return GreenBox::mean_square(token_buf_);
}
