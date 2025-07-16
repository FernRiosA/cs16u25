#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    while (true) {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;

        if (rows == 0 && cols == 0)
            break;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "X";
                if (j < cols - 1) {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
