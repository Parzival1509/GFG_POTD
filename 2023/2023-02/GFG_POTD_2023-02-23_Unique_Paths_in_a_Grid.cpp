// GFG POTD 2023/02/23
// Unique Paths in a Grid
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    
    int func(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = (func(i+1, j, n, m, grid)%mod + func(i, j+1, n, m, grid)%mod)%mod;
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        dp = vector<vector<int>> (n, vector<int> (m, -1));
        return func(0, 0, n, m, grid);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>grid[i][j];
        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}

/* Sample Input:
2
3 3
1 1 1
1 0 1
1 1 1
1 3
1 0 1

Sample Output:
2
0

*/