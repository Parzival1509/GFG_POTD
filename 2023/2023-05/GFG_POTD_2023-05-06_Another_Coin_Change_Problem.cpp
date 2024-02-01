// GFG POTD 2023/05/06
// Another Coin Change Problem
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int N, int k, int target, vector<int> &coins) {
        if(k == 0 && target == 0) return dp[target][k] = true;
        if(dp[target][k] != -1) return dp[target][k];
  
        bool ans = false;
        for(int i = 0; i <= N; i++)
            if(coins[i] <= target && k > 0)
                ans = ans || solve(N, k-1, target-coins[i], coins);
        return dp[target][k] = ans;
    }
    
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        dp = vector<vector<int>> (target+1, vector<int> (K+1, -1));
        return solve(N-1, K, target, coins);
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        int n, k, target;
        cin>>n>>k>>target;
        vector<int> coins(n, 0);
        for(int &i: coins)
            cin>>i;
        Solution obj;
        bool res = obj.makeChanges(n, k, target, coins);
        cout << res << endl;
    }
}

/* Sample Input:
2
5 3 11
1 10 5 8 6
3 5 25
7 2 4

Sample Output:
1
1

*/