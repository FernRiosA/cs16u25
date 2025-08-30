
// PLACE THE NECESSARY include, etc... STATEMENTS HERE
//

// DECLARE THE FUNCTIONS HERE:
// 

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
//

