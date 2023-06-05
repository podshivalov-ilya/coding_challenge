#pragma once
#include "box.hpp"

class BlueBox : public Box {
public:
    static int cantor(int x, int y);
    static double cantord(double x, double y);
public:
    BlueBox() = delete;
    explicit BlueBox(double initial_weight);

    void absorb(double token_weight) override;
private:
    double min_weight_;
    double max_weight_;
};
