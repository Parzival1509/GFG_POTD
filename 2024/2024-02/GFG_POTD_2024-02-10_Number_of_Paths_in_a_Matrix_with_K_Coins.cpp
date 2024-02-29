// GFG POTD 2024/02/10
// Number of Paths in a Matrix with K Coins
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101][101];
    
    long long solve(vector<vector<int>>&arr, int i, int j, int sum) {
        int n = arr.size();
        
        if(i == n - 1 and j == n - 1 and sum == arr[i][j])
            return 1;
        if(i >= n or j >= n or sum < 0) return 0;
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        return dp[i][j][sum] = solve(arr, i + 1, j, sum - arr[i][j]) + solve(arr, i, j + 1, sum - arr[i][j]);
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, 0, k);
    }
};

int main() {
    Solution obj;
    int i, j, k, l, m, n, t;
    cin >> t;
    while(t--) {
        cin >> k >> n;
        vector<vector<int>> v(n, vector<int> (n, 0));
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}

/* Sample Input:
2
12 3
1 2 3
4 6 5
3 2 1
16 3
1 2 3
4 6 5
9 8 7

Sample Output:
2
0

*/