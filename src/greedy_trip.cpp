#include <iostream>
#include "greedy_trip.hpp"

GreedyTrip::GreedyTrip(int total_money, int n_islands) {
    this->total_money = total_money;
    this->islands = new island[n_islands];
}

void GreedyTrip::add_island(int island_price, int island_points, int position) {
    this->islands[position].price = island_price;
    this->islands[position].points = island_points;
    this->islands[position].priceperpoint = (float)island_price/island_points;
}

void GreedyTrip::print_islands() {
    for (int i = 0; i < 5; i++)
        std::cout
            << this->islands[i].price << " "
            << this->islands[i].points << " "
            << this->islands[i].priceperpoint
            << std::endl;
    std::cout << std::endl;
}

std::pair<int, int> run() {
    //TODO: Greedy algorithm to solve islands problem
}