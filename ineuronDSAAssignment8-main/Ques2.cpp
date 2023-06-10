#include <iostream>
#include <stack>
using namespace std;

bool checkValidString(string s) {
    stack<int> leftStack, starStack;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            leftStack.push(i);
        } else if (s[i] == '*') {
            starStack.push(i);
        } else {
            if (!leftStack.empty()) {
                leftStack.pop();
            } else if (!starStack.empty()) {
                starStack.pop();
            } else {
                return false;
            }
        }
    }

    while (!leftStack.empty() && !starStack.empty()) {
        if (leftStack.top() > starStack.top()) {
            return false;
        }
        leftStack.pop();
        starStack.pop();
    }

    return leftStack.empty();
}

int main() {
    string s ;
    cin>>s;
    if (checkValidString(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

