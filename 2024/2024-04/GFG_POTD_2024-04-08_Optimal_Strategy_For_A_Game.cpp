// GFG POTD 2024/04/08
// Optimal Strategy For A Game
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll dfs(int left, int right, int arr[], vector<vector<int>>& dp) {
        if (left > right) return 0;
        
        if (dp[left][right] != -1)
            return dp[left][right];

        ll takeLeft = arr[left] + min(dfs(left + 2, right, arr, dp), dfs(left + 1, right - 1, arr, dp));
        ll takeRight = arr[right] + min(dfs(left + 1, right - 1, arr, dp), dfs(left, right - 2, arr, dp));

        return dp[left][right] = max(takeLeft, takeRight);
    }

    ll maximumAmount(int n, int arr[]) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(0, n - 1, arr, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(n, a) << endl;
    }
    return 0;
}

/* Sample Input
2
4
5 3 7 10
4
8 15 3 7

Sample Output
15
22

*/