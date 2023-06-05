#pragma once
#include "box.hpp"
#include <vector>

class Player {
 public:
  void takeTurn(uint32_t input_weight,
                const std::vector<std::unique_ptr<Box> >& boxes) {
    // TODO
  }
  double getScore() const { return score_; }

 private:
  double score_{0.0};
};
