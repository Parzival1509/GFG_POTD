// GFG POTD 2023/08/11
// Coin Change
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: Memoization
    // ll helper(int coins[], int n, int sum, vector<vector<int>> &dp) {
    //     // Base Case
    //     if(sum == 0) return 1;
    //     if(n == 0) return 0;
        
    //     if(dp[n][sum] != -1) return dp[n][sum];

    //     if(coins[n - 1] > sum)
    //         return dp[n][sum] = helper(coins, n - 1, sum, dp);
    //     return dp[n][sum] = helper(coins, n, sum - coins[n - 1], dp) + helper(coins, n - 1, sum, dp);
    // }
    
    ll count(int coins[], int n, int sum) {
        vector<vector<ll>> dp(n + 1, vector<ll> (sum + 1, -1));
        // return helper(coins, n, sum, dp);

        // Approach 2: Tabulation
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= sum; j++) {
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }

        return dp[n][sum];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for(int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

/* Sample Input:
4
4 3
1 2 3
10 4
2 5 3 6
5 3
1 2 5
3 1
2

Sample Output:
4
5
4
0

*/