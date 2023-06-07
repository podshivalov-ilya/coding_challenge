#pragma once
#include "box.hpp"

class BlueBox : public Box {
public:
    static double cantor(double x, double y);
public:
    BlueBox() = delete;
    explicit BlueBox(double initial_weight);

    double absorb(double token_weight) override;
private:
    double min_weight_;
    double max_weight_;
    bool is_initialized_;
};
