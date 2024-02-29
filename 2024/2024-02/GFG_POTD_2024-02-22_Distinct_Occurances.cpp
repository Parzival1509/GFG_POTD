// GFG POTD 2024/02/22
// Distinct Occurances
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int i, int j, int n, int m, string s, string t, vector<vector<int>> &dp) {
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) {
            int notTake = solve(i + 1, j, n, m, s, t, dp);
            int take = solve(i + 1, j + 1, n, m, s, t, dp);
            dp[i][j] = (notTake + take) % mod;
        }
        else dp[i][j] = solve(i + 1, j, n, m, s, t, dp) % mod;
        
        return dp[i][j] % mod;
    }
    
    int subsequenceCount(string s, string t) {
        int n = s.size(), m = t.size();
        
        // // Approach 1: Memoization
        // // T.C. = O(N * M), S.C. = O(N * M)
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        
        // return solve(0, 0, n, m, s, t, dp) % mod;
        
        // // Approach 2: Tabulation
        // // T.C. = O(N * M), S.C. = O(N * M)
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        // for(int i = 0; i <= n; i++)
        //     dp[i][m] = 1;
            
        // for(int i = n - 1; i >= 0; i--) {
        //     for(int j = m - 1; j >= 0; j--) {
        //         if(s[i] == t[j]) {
        //             int notTake = dp[i + 1][j];
        //             int take = dp[i + 1][j + 1];
        //             dp[i][j] = (notTake + take) % mod;
        //         }
        //         else dp[i][j] = dp[i + 1][j] % mod;
        //     }
        // }
        
        // return dp[0][0] % mod;
        
        // Approach 3: Tabulation (Space Optimization)
        // T.C. = O(N * M), S.C. = O(M)
        vector<int> next(m + 1), curr(m + 1);
        next[m] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            curr[m] = 1;
            for(int j = m - 1; j >= 0; j--) {
                if(s[i] == t[j]) {
                    int notTake = next[j];
                    int take = next[j + 1];
                    curr[j] = (notTake + take) % mod;
                }
                else curr[j] = next[j] % mod;
            }
            next = curr;
        }
        
        return next[0] % mod;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, tt;
        cin >> s >> tt;
        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;   
    } 
}

/* Sample Input
2
banana ban
geeksforgeeks ge

Sample Output
3
6

*/