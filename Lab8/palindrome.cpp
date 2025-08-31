#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// DECLARE THE FUNCTIONS HERE:
void cleanUp(string& str);
bool isPalindrome(const string& str);

int main() {
    string p;
    cout << "Enter sentence:\n";
    getline(cin, p);
    
    cleanUp(p);
    bool answer = isPalindrome(p);
   
    if (answer) {
        cout << "It is a palindrome.\n";
    } else {
        cout << "It is not a palindrome.\n";
    }

    return 0;
}

// DEFINE THE FUNCTIONS HERE:

void cleanUp(string& str) {
    string cleaned;
    for (char c : str) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    str = cleaned;
}

bool isPalindrome(const string& str) {
    if (str.length() <= 1) {
        return true;
    }
    
    if (str[0] != str[str.length() - 1]) {
        return false;
    }
    
    return isPalindrome(str.substr(1, str.length() - 2));
}
