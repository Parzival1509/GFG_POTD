// GFG POTD 2024/04/23
// Rohan's Love for Matrix
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        int mod = 1e9 + 7;
        if (n == 1 || n == 2)
            return 1;
        if (dp[n] != 0)
            return dp[n];

        int ans = (solve(n - 1, dp) % mod + solve(n - 2, dp) % mod) % mod;
        return dp[n] = ans;
    }

    int firstElement(int n) {
        vector<int> dp(n + 1, 0);
        return solve(n, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

/* Sample Input
2
3
4

Sample Output
2
3

*/