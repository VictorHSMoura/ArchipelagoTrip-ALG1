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

    if(island_points != 0)
        this->islands[position].priceperpoint = (float)island_price/island_points;
    else
        this->islands[position].priceperpoint = __INT_MAX__;
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

int Trip::mdc_two_numbers(int num1, int num2) {
    int remainder = num1%num2;
    while(remainder!=0) {
        num1 = num2;
        num2 = remainder;
        remainder = num1 % num2;         
    }
    return num2;
}

int Trip::mdc() {
    int general_mdc = this->islands[0].price;
    if(this->n_islands > 1) {
        for(int i = 1; i < this->n_islands; i++) {
            general_mdc = mdc_two_numbers(general_mdc, this->islands[i].price);
        }
    }
    return mdc_two_numbers(general_mdc, this->total_money);
}

void Trip::merge(int left, int middle, int right) { 
    int first_array_idx, second_array_idx, merged_array_idx; 
    int left_size = middle - left + 1;
    int right_size =  right - middle;
    island L[left_size], R[right_size];
  
    /* Copy data to temp arrays L[] and R[] */
    for (first_array_idx = 0; first_array_idx < left_size; first_array_idx++) 
        L[first_array_idx] = this->islands[left + first_array_idx]; 
    for (second_array_idx = 0; second_array_idx < right_size; second_array_idx++) 
        R[second_array_idx] = this->islands[middle + 1+ second_array_idx]; 
  
    /* Merge the temp arrays back into islands[left..right]*/
    first_array_idx = 0;
    second_array_idx = 0;
    merged_array_idx = left;
    while (first_array_idx < left_size && second_array_idx < right_size) { 
        if (L[first_array_idx].priceperpoint <= R[second_array_idx].priceperpoint) { 
            this->islands[merged_array_idx] = L[first_array_idx];
            first_array_idx++;
        } else { 
            this->islands[merged_array_idx] = R[second_array_idx]; 
            second_array_idx++;
        } 
        merged_array_idx++;
    } 
  
    /* Copy the remaining elements of L[], if there are any */
    while (first_array_idx < left_size) { 
        this->islands[merged_array_idx] = L[first_array_idx]; 
        first_array_idx++; 
        merged_array_idx++; 
    } 
  
    /* Copy the remaining elements of R[], if there are any */
    while (second_array_idx < right_size) { 
        this->islands[merged_array_idx] = R[second_array_idx]; 
        second_array_idx++; 
        merged_array_idx++; 
    } 
}

void Trip::mergeSort(int left, int right) {
    if (left < right) { 
        //Avoids overflow for large left and right
        int middle = left+(right-left)/2; 

        mergeSort(left, middle); 
        mergeSort(middle+1, right); 
  
        merge(left, middle, right); 
    }
}

std::pair<int, int> Trip::runGreedy() {
    int left_money = this->total_money;
    int repetitions;
    int gained_points = 0, days_spent = 0;

    mergeSort(0, this->n_islands - 1);

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


//TODO: Refactor the code to make it more understandable
std::pair<int, int> Trip::runDynamic() {
    int mdc_trip = mdc();
    int OPT_size = (this->total_money / mdc_trip) + 1;
    int **OPT = new int*[(this->n_islands + 1)];
    int gained_points = 0, days_spent = 0;

    for (int i = 0; i <= this->n_islands; i++) {
        OPT[i] = new int[OPT_size];
    }

    for (int i = 0; i < OPT_size; i++)
        OPT[0][i] = 0;
    for (int i = 1; i <= this->n_islands; i++) {
        for (int j = 0; j < OPT_size; j++) {
            int w_i = this->islands[i - 1].price / mdc_trip;
            if (w_i > j)
                OPT[i][j] = OPT[i - 1][j];
            else {
                int solution1 = OPT[i - 1][j];
                int solution2 = this->islands[i - 1].points + OPT[i - 1][j - w_i];

                OPT[i][j] = solution1 > solution2 ? solution1 : solution2;
            }
        }
    }

    int i = this->n_islands;
    int j = OPT_size - 1;
    while (i != 0 && j != 0){
        if (OPT[i - 1][j] != OPT[i][j]) {
            days_spent++;
            j -= this->islands[i - 1].price / mdc_trip;
        }
        i--;
    }

    gained_points = OPT[this->n_islands][OPT_size - 1];

    for (int i = 0; i < this->n_islands; i++)
        delete [] OPT[i];
    delete [] OPT;

    return std::pair<int, int>(gained_points, days_spent);
}