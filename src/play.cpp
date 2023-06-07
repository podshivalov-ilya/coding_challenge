#include "green_box.hpp"
#include "blue_box.hpp"
#include "player.hpp"
#include <iostream>

std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
    std::vector<std::unique_ptr<Box>> boxes;
    boxes.emplace_back(makeBox<GreenBox>(0.0));
    boxes.emplace_back(makeBox<GreenBox>(0.1));
    boxes.emplace_back(makeBox<BlueBox>(0.2));
    boxes.emplace_back(makeBox<BlueBox>(0.3));

    Player playerA;
    Player playerB;

    for(size_t i = 0; i < input_weights.size(); ++i)
        if (i % 2 == 0)
            playerA.takeTurn(input_weights[i], boxes);
        else
            playerB.takeTurn(input_weights[i], boxes);

    std::cout << "Scores: player " << playerA.getScore() << ", player B " << playerB.getScore() << std::endl;
    return std::make_pair(playerA.getScore(), playerB.getScore());
}

