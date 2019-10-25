typedef struct {
    int price;
    int points;
    float priceperpoint;
}island;

int mdc_two_numbers(int num1, int num2);
int mdc(island islands[], int total_value, int n_islands);
void merge(island islands[], int left, int middle, int right);
void mergeSort(island islands[], int left, int right);