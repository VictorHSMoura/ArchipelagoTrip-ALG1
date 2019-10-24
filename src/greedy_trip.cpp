#include <iostream>
#include <iterator>
#include "greedy_trip.hpp"

GreedyTrip::GreedyTrip(int total_money, int n_islands) {
    this->total_money = total_money;
    this->n_islands = n_islands;
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

std::pair<int, int> GreedyTrip::run() {
    //TODO: Greedy algorithm to solve islands problem
    // Steps:
    // 1. Run MergeSort to sort islands by price_per_point
    // 2. Iterate through each island adding it to solution
    //    if it fits on the the trip
    // 3. Sum the price and the points of the selected islands
    // 4. Return the total price and points 
    int left_money = this->total_money;
    int repetitions;
    int gained_points = 0, days_spent = 0;

    mergeSort(this->islands, 0, this->n_islands - 1);

    for (int i = 0; i < this->n_islands; i++) {
        if (this->islands[i].price <= left_money) {
            repetitions = left_money/this->islands[i].price;
            left_money -= repetitions * this->islands[i].price;
            days_spent += repetitions;
            gained_points += repetitions * this->islands[i].points;
        }
    }
    
    return std::pair<int, int>(gained_points, days_spent);
}