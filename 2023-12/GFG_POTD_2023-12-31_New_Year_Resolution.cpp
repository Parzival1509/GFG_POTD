// GFG POTD 2023/12/31
// New Year Resolution
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int sum) {
        return (sum % 20 == 0 || sum % 24 == 0 || sum == 2024);
    }
    
    int solve(int ind, int sum, int n, int coins[], vector<vector<int>> &dp) {
        if(ind == n)
            return sum > 0 && check(sum);
        
        if(sum > 0 and check(sum))
            return 1;
            
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
            
        return dp[ind][sum] = solve(ind + 1, sum, n, coins, dp) | solve(ind + 1, sum + coins[ind], n, coins, dp);
    }

    int isPossible(int n, int coins[]) {
        int sum = accumulate(coins, coins + n, 0);
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
        
        return solve(0, 0, n, coins, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int coins[N];
        for(int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }

    return 0;
}

/* Sample Input:
2
8
5 8 9 10 14 2 3 5
5
1 2 3 4 5

Sample Output:
1
0

*/