#include <iostream>
#include <utility>
#include "trip.hpp"

Trip::Trip(int total_money, int n_islands) {
    this->total_money = total_money;
    this->n_islands = n_islands;
    this->islands = new island[n_islands];
}

void Trip::add_island(int island_price, int island_points, int position) {
    this->islands[position].price = island_price;
    this->islands[position].points = island_points;
    this->islands[position].priceperpoint = (float)island_price/island_points;
}

void Trip::print_islands() {
    for (int i = 0; i < 5; i++)
        std::cout
            << this->islands[i].price << " "
            << this->islands[i].points << " "
            << this->islands[i].priceperpoint
            << std::endl;
    std::cout << std::endl;
}

std::pair<int, int> Trip::runGreedy() {
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

std::pair<int, int> Trip::runDynamic() {
    int **OPT = new int*[this->n_islands + 1];
    int mdc_trip = mdc(this->islands, this->total_money, this->n_islands);
    for (int i = 0; i < this->n_islands; i++) {
        OPT[i] = new int[this->total_money / mdc_trip];
    }

    for (int i = 0; i < this->n_islands; i++)
        delete [] OPT[i];
    delete [] OPT;
}
