// GFG POTD 2023/07/18
// Longest Repeating Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // T.C. = O(2^n)
    // S.C. = O(n) -> due to recursive call stack
    int solveRec(string& str1, string& str2, int i, int j) {
        if(i == str1.length()) return 0;
        if(j == str2.length()) return 0;
        
        int ans = 0;
        if(str1[i] == str2[j] && i != j)
            ans = 1 + solveRec(str1, str2, i + 1, j + 1);
        else ans = max(solveRec(str1, str2, i, j + 1), solveRec(str1, str2, i + 1, j));
            
        return ans;
    }
    
    // T.C. = O(n^2)
    // S.C. = O(n^2)
    int solveMem(string& str1, string& str2, int i, int j, vector<vector<int>>& dp) {
        if(i == str1.length()) return 0;
        if(j == str2.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
            
        int ans = 0;
        if(str1[i] == str2[j] && i != j)
            ans = 1 + solveMem(str1, str2, i + 1, j + 1, dp);
        else ans = max(solveMem(str1, str2, i, j + 1, dp), solveMem(str1, str2, i + 1, j, dp));
        
        return dp[i][j] = ans;
    }
    
    // T.C. = O(n^2)
    // S.C. = O(n^2)
    int solveTab(string& str1, string& str2) {
        int n = str1.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        for(int i = n - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if(str1[i] == str2[j] && i != j)
                    ans = 1 + dp[i+1][j+1];
                else ans = max( dp[i][j+1], dp[i+1][j] );
                dp[i][j] = ans;
            }
        
        return dp[0][0];
    }
    
    //T.C. = O(n^2)
    //S.C. = O(n)
    int solveSO(string& str1, string& str2) {
        int n = str1.length();
        vector<int>curr(n + 1, 0);
        vector<int>next(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if(str1[i] == str2[j] && i != j)
                    ans = 1 + next[j + 1];
                else ans = max( curr[j + 1], next[j] );
                curr[j] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }
    
public:
    int LongestRepeatingSubsequence(string str) {
       // //Recursive -> TLE
       // return solveRec(str, str, 0, 0);
      
       // // Memoization
       // int n = str.length();
       // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
       // return solveMem(str, str, 0, 0, dp);
      
       // // Tabulation
       // return solveTab(str, str);

        // Space Optimization
        return solveSO(str, str);
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << endl;
    }
    return 0;
}

/* Sample Input:
2
axxxy
axxzxy

Sample Output:
2
2

*/