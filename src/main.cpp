#include <iostream>

#include "greedy_trip.hpp"

#define TEST_ISLANDS 5

void main_test() {
    GreedyTrip g = GreedyTrip(6000, TEST_ISLANDS);
    int prices[TEST_ISLANDS] = {1000, 2000, 500, 5000, 2200};
    int points[TEST_ISLANDS] = {30, 32, 4, 90, 45};
    std::pair<int, int> result;

    for (int i = 0; i < TEST_ISLANDS; i++) {
        g.add_island(prices[i], points[i], i);
    }

    g.print_islands();

    result = g.run();
    std::cout << result.first << " " << result.second << std::endl;
}

int main(int argc, char const *argv[]) {

    main_test();

    return 0;
}