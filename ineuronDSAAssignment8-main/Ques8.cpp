#include <iostream>
#include <string>
using namespace std;

bool buddyStrings(string s, string goal) {
    if (s.length() != goal.length() || s.empty()) {
        return false;
    }

    if (s == goal) {
        // Check if there are duplicate characters in s
        int freq[26] = {0};
        for (char ch : s) {
            if (++freq[ch - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }

    int first = -1, second = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != goal[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else {
                return false;  // More than two mismatched characters
            }
        }
    }

    return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
}

int main() {
    string s , goal;
    cin>>s>>goal;
    bool result = buddyStrings(s, goal);

    cout << boolalpha << result << endl;

    return 0;
}

