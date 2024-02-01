// GFG POTD 2023/02/14
// Walls Coloring
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {   
public:
    // DP Space Optimisation
    // T.C. = O(n), S.C. = O(1)
    int minCost(vector<vector<int>> &colors, int n) {
        vector<int> dp(3, 0);
        dp[0] = colors[0][0];
        dp[1] = colors[0][1];
        dp[2] = colors[0][2];
        
        for(int i=1; i<n; i++) {
            int prev0 = dp[0];
            int prev1 = dp[1];
            int prev2 = dp[2];
            dp[0] = colors[i][0] + min(prev1, prev2);
            dp[1] = colors[i][1] + min(prev0, prev2);
            dp[2] = colors[i][2] + min(prev0, prev1);
        }
        return min({dp[0], dp[1], dp[2]});
    }

    // // DP Memoization
    // // T.C. = O(n), S.C. = O(n)
    // vector<vector<int>> dp;

    // int solve(vector<vector<int>> &colors, int i, int prev) {
    //     if(i < 0) return 0;
    //     if(dp[i][prev] != -1) return dp[i][prev];

    //     int ans = INT_MAX;

    //     if(prev == 0) {
    //         ans = min(ans, solve(colors, i-1, 1) + colors[i][1]);
    //         ans = min(ans, solve(colors, i-1, 2) + colors[i][2]);
    //     }
    //     if(prev == 1) {
    //         ans = min(ans, solve(colors, i-1, 0) + colors[i][0]);
    //         ans = min(ans, solve(colors, i-1, 2) + colors[i][2]);
    //     }
    //     if(prev == 2) {
    //         ans = min(ans, solve(colors, i-1, 0) + colors[i][0]);
    //         ans = min(ans, solve(colors, i-1, 1) + colors[i][1]);
    //     }
    //     return dp[i][prev] = ans;
    // }

    // int minCost(vector<vector<int>> &colors, int n) {
    //     dp = vector<vector<int>> (n, vector<int> (3, -1));

    //     int ans = INT_MAX;
    //     ans = min(ans, solve(colors, n-2, 0) + colors[n-1][0]);
    //     ans = min(ans, solve(colors, n-2, 1) + colors[n-1][1]);
    //     ans = min(ans, solve(colors, n-2, 2) + colors[n-1][2]);

    //     return ans;
    // }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}

/* Sample Input:
2
3
14 2 11
11 14 5
14 3 10
2
1 2 3
1 4 6

Sample Output:
10
3

*/