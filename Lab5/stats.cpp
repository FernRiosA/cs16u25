#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

// Functions
double calculateMean(const double numbers[], int count);
double calculateMedian(double numbers[], int count);
double calculateStdDev(const double numbers[], int count, double mean);
double calculateZeroProportion(const double numbers[], int count);

int main() {
    string filename;
    double numbers[1000];
    int count = 0;
    
    
    cout << "Enter filename: ";
    cin >> filename;
    
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "File could not be opened." << endl;
        return 1;
    }
    // Gets numbers
    double num;
    while (inputFile >> num && count < 1000) {
        numbers[count] = num;
        count++;
    }
    
    inputFile.close();
    
    //statistics
    double mean = calculateMean(numbers, count);
    double median = calculateMedian(numbers, count);
    double stddev = calculateStdDev(numbers, count, mean);
    double zeroProp = calculateZeroProportion(numbers, count);
    
    cout << "Mean = " << mean << endl;
    cout << "Median = " << median << endl;
    cout << "Stddev = " << stddev << endl;
    cout << "Zeroes = " << zeroProp * 100 << "%" << endl;
    
    return 0;
}

double calculateMean(const double numbers[], int count) {
    if (count == 0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

double calculateMedian(double numbers[], int count) {
    if (count == 0) return 0.0;
    
    // Bubble sort the array
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                // Swap
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    // Calculate median
    if (count % 2 == 1) {
        //For odd number of elements
        return numbers[count / 2];
    } else {
        // For even number of elements
        int mid = count / 2;
        return (numbers[mid - 1] + numbers[mid]) / 2.0;
    }
}

double calculateStdDev(const double numbers[], int count, double mean) {
    if (count <= 1) return 0.0;
    
    double sumSquaredDiffs = 0.0;
    for (int i = 0; i < count; i++) {
        double diff = numbers[i] - mean;
        sumSquaredDiffs += diff * diff;
    }
    
    return sqrt(sumSquaredDiffs / (count - 1));
}

double calculateZeroProportion(const double numbers[], int count) {
    if (count == 0) return 0.0;
    
    int zeroCount = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] == 0.0) {
            zeroCount++;
        }
    }
    
    return static_cast<double>(zeroCount) / count;
}
