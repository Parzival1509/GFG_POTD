// GFG POTD 2024/01/15
// Grinding Geek
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int> &cost, int total, int n, vector<vector<int>> &dp) {
        if(total <= 0) return 0;
        if(i == n) return 0;
        if(dp[i][total] != -1)
            return dp[i][total];
        
        int a = 0, b = 0;
        if(cost[i] <= total)
            a = 1 + solve(i + 1, cost, floor(total - cost[i] * 0.1), n, dp);
        b = solve(i + 1, cost, total, n, dp);
        
        return dp[i][total] = max(a, b);
    }

    int max_courses(int n, int total, vector<int> &cost) {
        vector<vector<int>> dp(n + 1, vector<int> (total + 1, -1));
        
        return solve(0, cost, total, n, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution ob;
        cout << ob.max_courses(n, k, arr) << endl;
    }
}

/* Sample Input:
2
2 10
10 9
11 10
10 1 1 1 1 1 1 1 1 1

Sample Output:
2
10

*/