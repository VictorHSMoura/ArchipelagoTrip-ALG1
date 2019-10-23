#include "utils.hpp"

void merge(island islands[], int left, int middle, int right) { 
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
  
    /* create temp arrays */
    island L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = islands[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = islands[middle + 1+ j]; 
  
    /* Merge the temp arrays back into islands[left..right]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i].priceperpoint <= R[j].priceperpoint) { 
            islands[k] = L[i]; 
            i++; 
        } else { 
            islands[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        islands[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        islands[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* left is for left index and right is right index of the 
   sub-array of islands to be sorted */
void mergeSort(island islands[], int left, int right) { 
    if (left < right) { 
        // Same as (left+right)/2, but avoids overflow for 
        // large left and h 
        int middle = left+(right-left)/2; 
  
        // Sort first and second halves 
        mergeSort(islands, left, middle); 
        mergeSort(islands, middle+1, right); 
  
        merge(islands, left, middle, right); 
    }
}