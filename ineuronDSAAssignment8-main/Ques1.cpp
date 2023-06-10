
#include <iostream>
#include <vector>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D table to store the minimum ASCII sum
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and column
    for (int i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] + s1[i - 1];

    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j - 1] + s2[j - 1];

    // Fill the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 ,s2;

    cin>>s1>>s2;
    cout << minimumDeleteSum(s1, s2) << endl;

    return 0;
}
