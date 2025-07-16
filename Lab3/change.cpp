#include <iostream>
#include <string>

using namespace std;

void compute_coins(int amount);

int main() {
    int cents;

    while (true) {
        cout << "Enter number of cents (or zero to quit):" << endl;
        cin >> cents;

        if (cents == 0) {
            break;
        }

        compute_coins(cents);

    }

    return 0;

}

void compute_coins(int amount) {
   
   if (amount < 1 || amount > 99) {
        cout << "Amount is out of bounds. Must be between 1 and 99." << endl;
        return;
    }
   
    int quarters = amount / 25;
    amount %= 25;
   
    int nickels = amount / 5;
    amount %= 5;
   
    int pennies = amount;

    cout << amount + quarters * 25 + nickels * 5 << " cent";

    if (amount + quarters * 25 + nickels * 5 != 1) {
        cout << "s";

    }
    
    cout <<" can be given in ";

    bool need_comma = false;

    if (quarters > 0) {
        cout << quarters << " quarter";
        if (quarters != 1) {
            cout << "s";
        }
        need_comma = true;
    }

    if (nickels > 0) {
        if (need_comma) {
            cout << ", ";
        }
        cout << nickels << " nickel";
        if (nickels != 1) {
            cout << "s";
        }
        need_comma = true;
    }

    if (pennies > 0) {
        if (need_comma) {
            cout << ", ";
        }
        cout << pennies << " penn";
        if (pennies != 1) {
            cout << "ies";
        } else {
            cout << "y";
        }
    }

    cout << "." << endl;
    
}
