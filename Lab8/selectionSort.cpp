#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

#include "headers.hpp"
#include "functions.cpp"

int main() {
    // This is an example of the program running and testing
    // an integer array found inside of an input file.
    // You can use this or a modified version of it for your testing.
    // We will have our own test suite.

    // READ THE ARRAY FROM THE FILE
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);

    // PRINT THE ORIGINAL ARRAY
    cout << "Original array:\n";
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    // ASK THE USER FOR SORT DIRECTION FIRST.
    bool descending;
    cout << "Ascending (0) or Descending (1): ";
    cin >> descending;

    // CALL THE SELECT SORT FUNCTION
    // Requirement: HAS TO BE DESIGNED AS A RECURSIVE FUNCTION
    int starting_index = 0;
    sort(descending, array, size, starting_index);

    // PRINT THE NOW SORTED ARRAY
    cout << "Sorted array:\n";
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

	return 0;
}
