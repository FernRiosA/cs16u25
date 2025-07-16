#include <iostream>
#include <string>

using namespace std;    

int main(int argc, char* argv[]) {
    // Part 1: Check to see if the number of arguments is correct
    if (argc != 4){
        cerr << "Number of arguments is incorrect." << endl;
        exit(1);
    }

    // Part 2: Convert arguments into integers (only those that need it!)
    int num1 = atoi(argv[1]);
    char op = argv[2][0];
    int num2 = atoi(argv[3]);

    // Part 3: Check for illegal operations like divide by zero...
    if (op!= '+' && op != '-' && op != '%') {
        cerr << "Bad operation choice." << endl;
        exit(1);
    }

    // Part 4: Do the appropriate calculation,
    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '%':
            result = num1 % num2;
            break;
    }

    cout << result << endl;

    return 0;
}

