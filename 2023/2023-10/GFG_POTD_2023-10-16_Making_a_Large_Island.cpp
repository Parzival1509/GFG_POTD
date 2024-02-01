// GFG POTD 2023/10/16
// Making a Large Island
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int isValid(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        return x < grid.size() and x >= 0 and y < grid[0].size() and y >= 0 and grid[x][y] == 1 and vis[x][y] == 0;
    }
    
    void dfsLen(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis, int& len) {
        len++;
        
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isValid(x, y, vis, grid))
                dfsLen(grid, x, y, vis, len);
        }
    }
    
    void dfs(vector<vector<int>>& isLandLen, int i, int j, vector<vector<int>>& mp, vector<vector<int>>& grid, int len, vector<vector<int>>& mpu) {
        isLandLen[i][j] = len;
        mpu[i][j] = t;
        mp[i][j] = 1;
        
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isValid(x, y, mp, grid))
                dfs(isLandLen, x, y, mp, grid, len, mpu);
        }
    }
    
    void solve(vector<vector<int>>& grid, vector<vector<int>>& islandLen, int i, int j, vector<vector<int>>& mpu, vector<vector<int>>& vis, vector<vector<int>>& mp) {
        int len = 0;
        dfsLen(grid, i, j, vis, len);
        dfs(islandLen, i, j, mp, grid, len, mpu);
        t++;
    }
    
    bool isV(int x, int y, int n, int m) {
        return x >= 0 and y >= 0 and x < n and y < m;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxi = INT_MIN;
        
        vector<vector<int>> mpu(n, vector<int> (m, 0)), isLandLen(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0)), mp(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1 and isLandLen[i][j] == 0)
                    solve(grid, isLandLen, i, j, mpu, vis, mp);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                unordered_map<int, int> mpk;
                
                if(grid[i][j] == 0) {
                    int s = 0;
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(isV(x, y, n, m) and mpk.find(mpu[x][y]) == mpk.end())
                            s += isLandLen[x][y];
                        if(isV(x, y, n, m) and grid[x][y] > 0)
                            mpk[mpu[x][y]]++;
                    }
                    maxi = max(1 + s, maxi);
                }
            }
        }
        
        return (maxi == INT_MIN)? n * m: maxi;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        Solution ob;
        cout << ob.largestIsland(grid) << endl;
    }

    return 0;
}

/* Sample Input:
3

2
1 0 
0 1

2
1 1
1 0

2
1 1
1 1

Sample Output:
3
4
4

*/