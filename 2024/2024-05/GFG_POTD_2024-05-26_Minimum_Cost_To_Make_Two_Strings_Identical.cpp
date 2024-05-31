// GFG POTD 2024/05/26
// Minimum Cost To Make Two Strings Identical
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string& x, string& y, int n, int m, vector<vector<int>>& dp) {
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (x[n] == y[m])
            return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1, dp);
        
        return dp[n][m] = max(lcs(x, y, n - 1, m, dp), lcs(x, y, n, m - 1, dp));
    }

    int findMinCost(string x, string y, int costX, int costY) {
        int n = x.size() - 1, m = y.size() - 1;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int len = lcs(x, y, n, m, dp);

        return costX * (n + 1 - len) + costY * (m + 1 - len);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        int costX, costY;
        cin >> costX >> costY;
        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY) << endl;
    }
    return 0;
}

/* Sample Input
2
abcd acdb 10 20
ef gh 10 20

Sample Output
30
60

*/