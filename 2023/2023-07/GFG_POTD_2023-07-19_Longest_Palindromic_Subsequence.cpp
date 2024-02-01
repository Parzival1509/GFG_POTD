// GFG POTD 2023/07/19
// Longest Palindromic Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
private :
    // Approach 1: Recursive
    // T.C. = O(2^N), S.C. = O(N) Stackspace
    int solveRecursive(int i, int j, string &A, vector<vector<int>> &dp) {
        if(i >= A.size() || j < 0) return 0;
        if(A[i] == A[j]) return 1 + solveRecursive(i + 1, j - 1, A, dp);
        
        return max(solveRecursive(i + 1, j, A, dp), solveRecursive(i, j - 1, A, dp));
    }
    
    // Approach 2: Memoization
    // T.C. = O(N^2), S.C. = O(N^2) + O(N) Stackspace
    int solveMemo(int i, int j, string &A, vector<vector<int>> &dp) {
        if(i >= A.size() || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(A[i] == A[j])
            return dp[i][j] = 1 + solveMemo(i + 1, j - 1, A, dp);
        
        return dp[i][j] = max(solveMemo(i + 1, j, A, dp), solveMemo(i, j - 1, A, dp));
    }
    
public:
    int longestPalinSubseq(string A) {
        int n = A.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        
        // return solveRecursive(0, n - 1, A, dp);
        // return solveMemo(0, n - 1, A, dp);
        
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        string B = A;
        reverse(B.begin(), B.end());
        
        // // Approach 3: Tabulation
        // // T.C. = O(N^2), S.C. = O(N^2)
        // for(int i = 0; i <= n; i++) {
        //     dp[i][0] = 0;
        //     dp[0][i] = 0;
        // }
        
        // for(int i = 1; i <= n; i++)
        //     for(int j = 1; j <= n; j++) {
        //         if(A[i-1] == B[j-1])
        //             dp[i][j] = 1 + dp[i - 1][j - 1];
        //         else
        //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //     }
        
        // return dp[n][n];
        
        // Approach 4: Linear Space Optmisation
        // T.C. = O(N^2), S.C. = O(N)
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for(int i = 1;i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(A[i - 1] == B[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        
        return curr[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}

/* Sample Input:
2
bbabcbcab
abcd

Sample Output:
7
1

*/