// GFG POTD 2023/05/26
// Express as Sum of Power of Natural Numbers
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
    
    int recu(vector<int> &v, int target, int p, int idx, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(idx == 0) return target == pow(v[idx], p);
        
        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = recu(v, target, p, idx-1, dp);
        int take = 0;
        if(target >= pow(v[idx], p))
            take = recu(v, target - pow(v[idx], p), p, idx-1, dp);
        return dp[idx][target] = (take + notTake) % mod;
    }

public:
    int numOfWays(int n, int x) {
        vector<int> v;
        int val = pow(n, 1.0/x);
        for(int i = 1; i <= val; i++)
            v.push_back(i);
        int sze = v.size();
        vector<vector<int>> dp(sze, vector<int>(n+1, -1));
        return recu(v, n, x, sze-1, dp) % mod;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

/* Sample Input:
2
10 2
100 2

Sample Output:
1
3

*/