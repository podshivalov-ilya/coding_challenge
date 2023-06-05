#pragma once
#include <memory>

class Box {
public:
    explicit Box(double initial_weight)
      : weight_(initial_weight) {}
    bool operator<(const Box& rhs) const { return weight_ < rhs.weight_; }

    static std::unique_ptr<Box> makeGreenBox(double initial_weight);
    static std::unique_ptr<Box> makeBlueBox(double initial_weight);

    virtual void absorb(double token_weight) = 0;
    virtual double score() = 0;

protected:
    double weight_;
};

