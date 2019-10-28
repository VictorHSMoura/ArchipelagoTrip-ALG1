#include <iostream>
#include <cstdlib>
#include <fstream>

#include "trip.hpp"

int main(int argc, char const *argv[]) {
    int max_value, n_islands;
    int island_price, island_points;
    std::pair<int, int> trip_result_greedy, trip_result_dynamic;
    std::ifstream input_file;
    std::string line;

    if (argc <= 1) exit(1);

    input_file.open(argv[1]);
    if (input_file.is_open()) {
        input_file >> max_value >> n_islands;
        Trip trip = Trip(max_value, n_islands);

        for (int i = 0; i < n_islands; i++) {
            input_file >> island_price >> island_points;
            trip.add_island(island_price, island_points, i);
        }

        if (n_islands > 0) {
            trip_result_dynamic = trip.runDynamic();
            trip_result_greedy = trip.runGreedy();

            std::cout << trip_result_greedy.first << " " << trip_result_greedy.second << std::endl;
            std::cout << trip_result_dynamic.first << " " << trip_result_dynamic.second << std::endl;
        }
        input_file.close();
    }
    return 0;
}
