#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    unordered_map<char, int> targetFreq, windowFreq;
    int pSize = p.size();
    int sSize = s.size();

    // Calculate the frequency of characters in p
    for (char ch : p) {
        targetFreq[ch]++;
    }

    int left = 0, right = 0;
    int count = 0; // Count of matched characters

    while (right < sSize) {
        char currentChar = s[right];

        // Expand the window
        if (targetFreq.count(currentChar) > 0) {
            windowFreq[currentChar]++;
            if (windowFreq[currentChar] <= targetFreq[currentChar]) {
                count++;
            }
        }

        // Shrink the window
        if (right - left + 1 > pSize) {
            char leftChar = s[left];
            if (targetFreq.count(leftChar) > 0) {
                windowFreq[leftChar]--;
                if (windowFreq[leftChar] < targetFreq[leftChar]) {
                    count--;
                }
            }
            left++;
        }

        // Check if an anagram is found
        if (count == pSize) {
            result.push_back(left);
        }

        right++;
    }

    return result;
}

int main() {
    string s ,p;
    cin>>s>>p;

    vector<int> indices = findAnagrams(s, p);

    // Print the indices
    for (int idx : indices) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

