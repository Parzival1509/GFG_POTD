// GFG POTD 2023/09/14
// Perfect Sum Problem
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int arr[], int n, int sum, vector<vector<int>> &dp) {
        if(sum == 0 && n == 0) return 1;
        if(n == 0) return 0;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        int pick = 0, notPick = 0;
        if(arr[n - 1] <= sum) pick = solve(arr, n - 1, sum - arr[n - 1], dp);

        notPick = solve(arr, n - 1, sum, dp);

        return dp[n][sum] = (pick + notPick) % mod;
    }

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
        return solve(arr, n, sum, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, sum;
        cin >> n >> sum;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
         
    }
    return 0;
}

/* Sample Input:
2
6 10
2 3 5 6 8 10
5 10
1 2 3 4 5

Sample Output:
3
3

*/