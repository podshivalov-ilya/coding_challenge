#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "blue_box.hpp"
#include "green_box.hpp"
#include "play.hpp"

TEST_CASE("Test Cantor function") {
    REQUIRE(1.0 == BlueBox::cantor(1.0, 0.0));
    REQUIRE(2.0 == BlueBox::cantor(0.0, 1.0));
    REQUIRE(3.0 == BlueBox::cantor(2.0, 0.0));
    REQUIRE(4.0 == BlueBox::cantor(1.0, 1.0));
}

TEST_CASE("Test mean square function") {
    std::queue<double> test_queue({0.0, 1.0});
    REQUIRE(0.25 == GreenBox::mean_square(test_queue));
    test_queue = std::queue<double>({0.0, 1.0, 2.0});
    REQUIRE(1.0 == GreenBox::mean_square(test_queue));
    test_queue = std::queue<double>({2.0, 4.0, 6.0});
    REQUIRE(16.0 == GreenBox::mean_square(test_queue));
    test_queue = std::queue<double>({2.0, 3.0, 4.0, 5.0, 6.0});
    REQUIRE(16.0 == GreenBox::mean_square(test_queue));
}

TEST_CASE("Test absorption of green box", "[green]") {
    GreenBox green_box(0.0);
    REQUIRE(green_box.score() == Approx(0.0));
    green_box.absorb(0.1);
    green_box.absorb(0.2);
    green_box.absorb(0.3);
    REQUIRE(green_box.score() == Approx(0.2 * 0.2));
    green_box.absorb(0.4);
    REQUIRE(green_box.score() == Approx(0.3 * 0.3));
}

TEST_CASE("Test absorption of blue box", "[blue]") {
    BlueBox blue_box(0.2);
    REQUIRE(blue_box.score() == Approx(0.2));
    blue_box.absorb(3.0);
    blue_box.absorb(2.0);
    REQUIRE(blue_box.score() == BlueBox::cantor(0.2, 3.0));
    blue_box.absorb(1.0);
    REQUIRE(blue_box.score() == BlueBox::cantor(0.2, 3.0));
    blue_box.absorb(4.0);
    REQUIRE(blue_box.score() == BlueBox::cantor(0.2, 4.0));
}

TEST_CASE("Test Box polymorphism") {
    std::unique_ptr<Box> green_box = makeBox<GreenBox>(0.0);
    std::unique_ptr<Box> blue_box = makeBox<BlueBox>(0.2);

    blue_box->absorb(3.0);
    blue_box->absorb(2.0);
    blue_box->absorb(1.0);
    REQUIRE(blue_box->score() == BlueBox::cantor(0.2, 3.0));

    green_box->absorb(0.1);
    green_box->absorb(0.2);
    green_box->absorb(0.3);
    REQUIRE(green_box->score() == Approx(0.2 * 0.2));
}

TEST_CASE("Final scores for first 4 Fibonacci numbers", "[fibonacci4]") {
    std::vector<uint32_t> inputs{1, 1, 2, 3};
    auto result = play(inputs);
    REQUIRE(result.first == 13.0);
    REQUIRE(result.second == 25.0);
}

TEST_CASE("Final scores for first 8 Fibonacci numbers", "[fibonacci8]") {
    std::vector<uint32_t> inputs{1, 1, 2, 3, 5, 8, 13, 21};
    auto result = play(inputs);
    REQUIRE(result.first == 155.0);
    REQUIRE(result.second == 366.25);
}
