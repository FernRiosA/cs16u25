#include <iostream>
#include <fstream>
#include <string>
#include "headers.hpp"

using namespace std;



void swap_values(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

)
int find_index_of_swap(bool descending, const int arr[], int size, int start_index) {
    int target_index = start_index;
    
    for (int i = start_index + 1; i < size; i++) {
        if (descending) {
            if (arr[i] > arr[target_index]) {
                target_index = i;
            }
        } else {
            if (arr[i] < arr[target_index]) {
                target_index = i;
            }
        }
    }
    
    return target_index;
}

void sort(bool descending, int arr[], int size, int start_index) {
    // Base case: if we've reached the end of the array
    if (start_index >= size - 1) {
        return;
    }
    
    int swap_index = find_index_of_swap(descending, arr, size, start_index);
    
    if (swap_index != start_index) {
        swap_values(arr[start_index], arr[swap_index]);
    }
    
    sort(descending, arr, size, start_index + 1);
}

// Next, define the function getArray here. 
// This is the same one we used in Lab 4, so you can copy it over as is.
void getArray(ifstream& ifs, const string& filename, int arr[], int& size) {
    ifs.open(filename);
    if (!ifs.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }
    
    int count = 0;
    int num;
    
    // Read integers from file until EOF or array is full
    while (ifs >> num && count < MAXSIZE) {
        arr[count] = num;
        count++;
    }
    
    size = count; // Update the actual size
    ifs.close();
}
