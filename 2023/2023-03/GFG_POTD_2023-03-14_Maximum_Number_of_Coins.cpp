// GFG POTD 2023/03/14
// Maximum Number of Coins
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&v, int i, int j, int low, int high, vector<vector<int>>&dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int l = i; l <= j; l++)
            dp[i][j] = max(dp[i][j], low*high*v[l] + solve(v, i, l-1, low, v[l], dp) + solve(v, l+1, j, v[l], high, dp));

        return dp[i][j];
    }

    int maxCoins(int n, vector <int> &a) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(a, 0, n-1, 1, 1, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n, a)<<endl;
    }
    return 0;
}

/* Sample Input:
2
2
5 10
4
3 1 5 8

Sample Output:
60
167

*/