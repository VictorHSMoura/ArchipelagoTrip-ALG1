#ifndef GREEDY_TRIP_HPP
#define GREEDY_TRIP_HPP

#include "utils.hpp"

class Trip {
private:
    int total_money;
    int n_islands;
    island *islands;

public:
    Trip(int total_money, int n_islands);
    void add_island(int island_price, int island_points, int position);
    void print_islands();
    std::pair<int, int> runGreedy();
    std::pair<int, int> runDynamic();
};

#endif