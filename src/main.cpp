#include "player.hpp"
#include <iostream>
#include <vector>

std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
  std::vector<std::unique_ptr<Box> > boxes;
  boxes.emplace_back(makeBox<GreenBox>(0.0));
  boxes.emplace_back(makeBox<GreenBox>(0.1));
  boxes.emplace_back(makeBox<BlueBox>(0.2));
  boxes.emplace_back(makeBox<BlueBox>(0.3));

  // TODO

  // std::cout << "Scores: player A " << player_A.getScore() << ", player B "
  //           << player_B.getScore() << std::endl;
  // return std::make_pair(player_A.getScore(), player_B.getScore());
  return {};
}

int main(int argc, char *argv[]) {
    return 0;
}
