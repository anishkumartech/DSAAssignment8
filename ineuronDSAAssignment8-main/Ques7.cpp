#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString;
    int currentCount = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            currentCount = currentCount * 10 + (ch - '0');
        } else if (isalpha(ch)) {
            currentString += ch;
        } else if (ch == '[') {
            countStack.push(currentCount);
            stringStack.push(currentString);
            currentCount = 0;
            currentString.clear();
        } else if (ch == ']') {
            string decodedString = stringStack.top();
            stringStack.pop();
            int repeatCount = countStack.top();
            countStack.pop();

            for (int i = 0; i < repeatCount; i++) {
                decodedString += currentString;
            }

            currentString = decodedString;
        }
    }

    return currentString;
}

int main() {
    string s ;
    cin>>s;
    string decodedString = decodeString(s);

    cout << decodedString << endl;

    return 0;
}

