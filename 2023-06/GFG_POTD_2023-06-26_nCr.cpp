// GFG POTD 2023/06/26
// nCr
// Medium

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int solve(int n, int r, vector<vector<int>> &dp) {
        if(n < r) return 0;
        if(n == r || r == 0) return 1;
        if(dp[n][r] != -1) return dp[n][r];
        
        return dp[n][r] = (solve(n - 1, r, dp) % MOD + solve(n - 1, r - 1, dp) % MOD) % MOD;
    }

    int nCr(int n, int r) {
        vector<vector<int>> dp(n + 1, vector<int> (r + 1, -1));
        return solve(n, r, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 2
2 4

Sample Output:
3
0

*/