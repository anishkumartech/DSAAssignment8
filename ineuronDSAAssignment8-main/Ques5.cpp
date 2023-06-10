
#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int index = 0; // Index to track the current position in the compressed array
    int count = 1; // Count of consecutive repeating characters

    for (int i = 1; i < n; i++) {
        if (chars[i] == chars[i - 1]) {
            count++;
        } else {
            chars[index++] = chars[i - 1]; // Store the current character

            // If the count is greater than 1, store the count as well
            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    chars[index++] = ch;
                }
            }

            count = 1; // Reset the count for the new character
        }
    }

    // Store the last character and its count
    chars[index++] = chars[n - 1];
    if (count > 1) {
        string countStr = to_string(count);
        for (char ch : countStr) {
            chars[index++] = ch;
        }
    }

    return index; // Return the new length of the compressed array
}

int main() {
    //vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    vector<char> chars;
    char ch;

    while (cin >> ch && isalpha(ch)) {
        chars.push_back(ch);
    }

    int newLength = compress(chars);

    // Print the compressed array
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
