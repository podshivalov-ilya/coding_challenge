#pragma once
#include "box.hpp"
#include <queue>

class GreenBox : public Box {
public:
    static double mean_square(std::queue<double> tmp_buf);
public:
    GreenBox() = delete;
    explicit GreenBox(double initial_weight);
    void absorb(double token_weight) override;
private:
    std::queue<double> token_buf_;
};
