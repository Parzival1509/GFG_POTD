// GFG POTD 2024/02/24
// Maximum Sum Problem
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return dp[n] = n;
        if (dp[n] != -1)
            return dp[n];

        int ans = solve(n / 2, dp) + solve(n / 3, dp) + solve(n / 4, dp);

        return dp[n] = max(n, ans);
    }

    int maxSum(int n) {
        vector<int> dp(n + 1, -1);
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
        cout << ob.maxSum(n) << "\n";
    }

    return 0;
}

/* Sample Input
3
12
24
1200

Sample Output
13
27
1755

*/