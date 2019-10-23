#include "greedy_trip.hpp"

GreedyTrip::GreedyTrip(int total_money, int n_islands) {
    this->total_money = total_money;
    this->islands = new island[n_islands];
}

void GreedyTrip::add_island(int island_price, int island_points, int position) {
    this->islands[position].price = island_price;
    this->islands[position].points = island_points;
}