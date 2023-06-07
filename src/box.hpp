#pragma once
#include <memory>

class Box {
public:
    Box() = delete;
    explicit Box(double initial_weight)
      : weight_(initial_weight) {}
    virtual ~Box() = default;
    bool operator<(const Box& rhs) const { return weight_ < rhs.weight_; }

    virtual double absorb(double token_weight) = 0;
    double weight() const { return weight_; }

protected:
    double weight_;
};

template<typename T>
concept BoxInstance = std::is_base_of<Box, T>::value;

template<BoxInstance T>
std::unique_ptr<Box> makeBox(double initial_weight) {
    return std::make_unique<T>(initial_weight);
}
