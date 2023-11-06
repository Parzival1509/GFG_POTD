// GFG POTD 2023/10/27
// Minimum Deletions
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveMemo(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + solveMemo(s, t, i - 1, j - 1, dp);
        return dp[i][j] = max(solveMemo(s, t, i, j - 1, dp), solveMemo(s, t, i - 1, j, dp));
    }

    int solveTab(string &s, string &t, int n, vector<vector<int>> &dp) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }

        return dp[n][n];
    }

    int solveTabOpt(string &s, string &t, int n, vector<int> &curr, vector<int> &prev) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return curr[n];
    }

    int minimumNumberOfDeletions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        
        // // Approach 1: Memoization (Bottom-Up)
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // return n - solveMemo(s, t, n, n, dp);

        // // Approach 2: Tabulation (Top-Down)
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        // return n - solveTab(s, t, n, dp);

        // Approach 3: Space Optimized DP
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        return n - solveTabOpt(s, t, n, curr, prev);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }

    return 0;
}

/* Sample Input:
3
aebcbda
geeksforgeeks
eebeeia

Sample Output:
2
8
2

*/