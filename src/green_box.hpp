#pragma once
#include "box.hpp"
#include <queue>

class GreenBox : public Box {
private:
    double current_weight() const;
public:
    GreenBox() = delete;
    explicit GreenBox(double initial_weight);
    void absorb(double token_weight) override;
private:
    std::queue<double> token_buf_;
};
