// GFG POTD 2023/08/10
// Longest Common Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Memoization
    int helper(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];

        // Last characters matched
        if(s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + helper(n - 1, m - 1, s1, s2, dp);
        
        // Last characters did not match
        return dp[n][m] = max(helper(n - 1, m, s1, s2, dp), helper(n, m - 1, s1, s2, dp));
    }

    int lcs(int n, int m, string s1, string s2) {
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return helper(n, m, s1, s2, dp);
        
        // Approach 2: Tabulation (Top-Down Approach)
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            
        return dp[n][m];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

/* Sample Input:
2
6 6
ABCDGH AEDFHR
3 2
ABC AC

Sample Output:
3
2

*/