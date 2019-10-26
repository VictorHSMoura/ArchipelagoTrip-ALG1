#ifndef GREEDY_TRIP_HPP
#define GREEDY_TRIP_HPP

typedef struct {
    int price;
    int points;
    float priceperpoint;
}island;
class Trip {
private:
    int total_money;
    int n_islands;
    island *islands;

    int mdc_two_numbers(int num1, int num2);
    int mdc();
    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);

public:
    Trip(int total_money, int n_islands);
    void add_island(int island_price, int island_points, int position);
    void print_islands();
    std::pair<int, int> runGreedy();
    std::pair<int, int> runDynamic();
};

#endif