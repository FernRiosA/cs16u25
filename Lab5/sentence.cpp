#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int sort_string(string &sentence);
void print_freq(const string &sentence);

int main()
{
    string sentence;

    // Ask user for sentence
    cout << "Enter sentence: ";
    getline(cin, sentence);

    int removed = sort_string(sentence);
    print_freq(sentence);
    cout << "removed: " << removed << endl;

    return 0;
}

int sort_string(string &sentence)
{
    int removed = 0;
    int n = sentence.length();
    
    // Convert to uppercase and remove non-alphabetical characters
    for (int i = 0; i < n; i++) {
        if (!isalpha(sentence[i])) {
            //Non-alphabetical characters
            sentence[i] = '\0'; // Use null character to mark for removal
            removed++;
        } else {
            // Convert to uppercase
            sentence[i] = toupper(sentence[i]);
        }
    }
    
    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sentence[j] == '\0' || (sentence[j + 1] != '\0' && sentence[j] > sentence[j + 1])) {
                // Swap characters
                char temp = sentence[j];
                sentence[j] = sentence[j + 1];
                sentence[j + 1] = temp;
            }
        }
    }
    
    // New Length
    int new_length = n - removed;
    
    sentence.resize(new_length);
    
    return removed;
}

void print_freq(const string &sentence)
{
    cout << "Sorted and cleaned-up sentence: " << sentence << endl;
    
    if (sentence.empty()) {
        return;
    }
    
    // Count frequency of each letter
    int freq[26] = {0}; // Array to store frequency
    
    for (char c : sentence) {
        if (isalpha(c)) {
            freq[c - 'A']++;
        }
    }
    
    // Print frequency of each letter
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            char letter = 'A' + i;
            cout << letter << ": " << freq[i] << endl;
        }
    }
}
