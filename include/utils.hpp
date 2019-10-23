typedef struct {
    int price;
    int points;
    float priceperpoint;
}island;

void merge(island islands[], int left, int middle, int right);
void mergeSort(island islands[], int left, int right);