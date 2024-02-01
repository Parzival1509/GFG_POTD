// GFG POTD 2023/10/24
// Palindromic Partitioning
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(string &s, int i, int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(isPalindrome(s, i, j)) return 0;
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            int left, right;
            
            // Left Subproblem
            if(dp[i][k] != -1)
                left = dp[i][k];
            else dp[i][k] = left = solve(s, i, k);
            
            // Right Subproblem
            if(dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else dp[k + 1][j] = right = solve(s, k + 1, j);
            
            int tmp = 1 + left + right;
            ans = min(ans, tmp);
        }
        
        return dp[i][j] = ans;
    }
    
    int palindromicPartition(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }

    return 0;
}

/* Sample Input:
2
aaabba
ababbbabbababa

Sample Output:
1
3

*/