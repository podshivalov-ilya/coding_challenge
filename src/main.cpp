#include "player.hpp"

std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
  std::vector<std::unique_ptr<Box> > boxes;
  boxes.emplace_back(Box::makeGreenBox(0.0));
  boxes.emplace_back(Box::makeGreenBox(0.1));
  boxes.emplace_back(Box::makeBlueBox(0.2));
  boxes.emplace_back(Box::makeBlueBox(0.3));

  // TODO

  std::cout << "Scores: player A " << player_A.getScore() << ", player B "
            << player_B.getScore() << std::endl;
  return std::make_pair(player_A.getScore(), player_B.getScore());
}

int main(int argc, char *argv[]) {
    return 0;
}
