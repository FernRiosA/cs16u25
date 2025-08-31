#include <iostream>
#include <fstream>
#include <string>


void getArray(std::ifstream& ifs, const std::string& filename, int arr[], int& size);


void sort(bool descending, int arr[], int size, int start_index);


int find_index_of_swap(bool descending, const int arr[], int size, int start_index);


void swap_values(int& a, int& b);

const int MAXSIZE = 20;     // amount of integers in the file (you need this to declare your array size)
const std::string FILENAME = "ArrayFile.txt";    // The file name with the integers
