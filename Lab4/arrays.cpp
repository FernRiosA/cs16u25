/*
/ Skeleton file for arrays.cpp for CS16, 2021, UCSB
/ Copyright © 2021 by Zachary Sisco. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.hpp"    // contains the function declarations
#include "constants.hpp"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);


    
    print_array(array, size);
    cout << endl;
    
    // Maximum value
    cout << "Max = " << maxArray(array, size) << endl;
    
    // Minimum value
    cout << "Min = " << minArray(array, size) << endl;
    
    // Sum
    cout << "Sum = " << sumArray(array, size) << endl;
    
    // Even numbers
    cout << "Evens: ";
    evensArray(array, size);
    cout << "end" << endl;
    
    // Prime numbers
    cout << "Primes: ";
    primesArray(array, size);
    cout << "end" << endl;
    
    cout << "Searches:" << endl;
    AllSearches(array, size);

    return 0;
}

// Function definitions
void print_array(int arr[], int asize) {
    for (int i = 0; i < asize; i++) {
        cout << arr[i];
        if (i < asize - 1) {
            cout << ", ";
        }
    }
}

int maxArray(int arr[], int asize) {
    int max = arr[0];
    for (int i = 1; i < asize; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minArray(int arr[], int asize) {
    int min = arr[0];
    for (int i = 1; i < asize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int sumArray(int arr[], int asize) {
    int sum = 0;
    for (int i = 0; i < asize; i++) {
        sum += arr[i];
    }
    return sum;
}

void evensArray(int arr[], int asize) {
    bool first = true;
    for (int i = 0; i < asize; i++) {
        if (arr[i] % 2 == 0) {
            if (!first) {
                cout << ", ";
            }
            cout << arr[i];
            first = false;
        }
    }
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void primesArray(int arr[], int asize) {
    bool first = true;
    for (int i = 0; i < asize; i++) {
        if (arr[i] > 0 && isPrime(arr[i])) {
            if (!first) {
                cout << ", ";
            }
            cout << arr[i];
            first = false;
        }
    }
}

int SeqSearch(int arr[], int asize, int target) {
    for (int i = 0; i < asize; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void AllSearches(int arr[], int asize) {
    for (int i = 0; i < NSEARCHES; i++) {
        int target = SEARCHES[i];
        int index = SeqSearch(arr, asize, target);
        
        cout << "Looking for " << target << ". ";
        if (index != -1) {
            cout << "Found at index: " << index;
        } else {
            cout << "Not Found!";
        }
        cout << endl;
    }
}
