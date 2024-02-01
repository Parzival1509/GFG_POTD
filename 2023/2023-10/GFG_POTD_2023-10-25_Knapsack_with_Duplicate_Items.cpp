// GFG POTD 2023/10/25
// Knapsack with Duplicate Items
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memoization
    int solve(int ind, int n, int W, int val[], int wt[], vector<vector<int>>& dp) {
        if(ind >= n) return 0;
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int skip = 0 + solve(ind + 1, n, W, val, wt, dp);
        int take = 0;
        if(wt[ind] <= W)
            take = val[ind] + solve(ind, n, W - wt[ind], val, wt, dp);
        
        return dp[ind][W] = max(skip, take);
    }
    
    // Tabulation
    int fTab(int N, int K, int val[], int wt[]) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        
        for(int ind = N - 1; ind >= 0; ind--) {
            for(int W = 0; W <= K; W++) {
                int skip = 0 + dp[ind + 1][W];
                int take = 0;
                if(wt[ind] <= W)
                    take = val[ind] + dp[ind][W - wt[ind]];
                
                dp[ind][W] = max(skip, take);
            }
        }
        
        return dp[0][K];
    }
    
    // Space Optimized Code
    int Space_Opti(int N, int K, int val[], int wt[]) {
        vector<int> curr(K + 1, 0), next(K + 1, 0);
        
        for(int ind = N - 1; ind >= 0; ind--) {
            for(int W = 0; W <= K; W++) {
                int skip = 0 + next[W];
                int take = 0;
                if(wt[ind] <= W)
                    take = val[ind] + curr[W - wt[ind]];
                
                curr[W] = max(skip, take);
            }
            next = curr;
        }
        
        return curr[K];
    }

    int knapSack(int N, int W, int val[], int wt[]) {
        // vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        // return solve(0, N, W, val, wt, dp);
        
        // return fTab(N, W, val, wt);
        
        return Space_Opti(N, W, val, wt);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for(int i = 0; i < N; i++)
            cin >> val[i];
        for(int i = 0; i < N; i++)
            cin >> wt[i];
        
        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }

    return 0;
}

/* Sample Input:
2
2 3
1 1
2 1
4 8
6 1 7 7
1 3 4 5

Sample Output:
3
48

*/