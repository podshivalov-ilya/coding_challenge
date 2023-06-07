#pragma once
#include "box.hpp"
#include <string>
#include <vector>
#include <iostream>

class Player final {
public:
    Player()
        : score_(0.0) {}
    void takeTurn(uint32_t input_weight, std::vector<std::unique_ptr<Box>>& boxes) {
        auto smallest_box_it = std::min_element(boxes.begin(), boxes.end(),
                                               [] (const std::unique_ptr<Box>& a, const std::unique_ptr<Box>& b)
                                               { return *a < *b; });
        Box* box = smallest_box_it->get();
        box->absorb(input_weight);
        score_ += box->score();
    }
    double getScore() const { return score_; }

private:
    double score_;
};
