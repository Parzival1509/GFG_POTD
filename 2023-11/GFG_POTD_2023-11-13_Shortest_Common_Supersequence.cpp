// GFG POTD 2023/11/13
// Shortest Common Supersequence
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestCommonSupersequence(string x, string y, int m, int n) {
        // // Approach 1: Tabulation
        // int dp[m + 1][n + 1];
        
        // for(int i = 0; i <= m; i++)
        //     for(int j = 0; j <= n; j++) {
        //         if(i == 0 || j == 0)
        //             dp[i][j] = 0;
        //         else if(x[i - 1] == y[j - 1])
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //     }
            
        // return m + n - dp[m][n];
        
        // Approach 2: Space Optimized Tabulation
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(x[i - 1] == y[j - 1])
                    curr[j] = prev[j - 1] + 1;
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        
        return m + n - curr[n];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestCommonSupersequence(x, y, x.size(), y.size()) << endl;
    }

    return 0;
}

/* Sample Input:
3
abcd xycd
efgh jghi
aaaaa aa

Sample Output:
6
6
5

*/