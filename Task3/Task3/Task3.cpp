#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class TextProcessor {
public:
    int countOddLengthWords(const string& text) {
        istringstream iss(text);
        string word;
        int count = 0;
        while (iss >> word) {
            if (word.length() % 2 != 0) {
                count++;
            }
        }
        return count;
    }

    void letterFrequency(const string& text) {
        unordered_map<char, int> frequency;
        for (char c : text) {
            if (isalpha(c)) {
                frequency[c]++;
            }
        }
        for (const auto& pair : frequency) {
            cout << pair.first << ": " << pair.second << " ";
        }
        cout << endl; // Print on the same line
    }

    string removeTextInBrackets(const string& text) {
        string result;
        bool inBrackets = false;
        for (char c : text) {
            if (c == '(') {
                inBrackets = true;
            }
            else if (c == ')') {
                inBrackets = false;
            }
            else if (!inBrackets) {
                result += c;
            }
        }
        return result;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    TextProcessor processor;
    int oddLengthCount = processor.countOddLengthWords(input);
    cout << "Number of words with odd length: " << oddLengthCount << endl;
    cout << "Frequency of each letter: ";
    processor.letterFrequency(input);
    string modifiedText = processor.removeTextInBrackets(input);
    cout << "Text without brackets: " << modifiedText << endl;
    return 0;
}
