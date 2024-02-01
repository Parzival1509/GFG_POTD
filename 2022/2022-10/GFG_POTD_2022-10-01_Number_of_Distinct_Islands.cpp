// GFG POTD Number of Distinct Islands

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, string &s){
        s += 1;
        grid[i][j] *= -1;
        if(i>0 && grid[i - 1][j]>0){
            s += 'U';
            dfs(grid, i - 1, j, n, m, s);
            s += 'U';
        }
        if(i<n-1 && grid[i+1][j]>0){
            s += 'D';
            dfs(grid, i + 1, j, n, m, s);
            s += 'D';
        }
        if(j>0 && grid[i][j-1]>0){
            s += 'L';
            dfs(grid, i, j - 1, n, m, s);
            s += 'L';
        }
        if(j<m-1 && grid[i][j+1]>0){
            s += 'R';
            dfs(grid, i, j + 1, n, m, s);
            s += 'R';
        }
        return;
    }
    int countDistinctIslands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] <= 0)
                    continue;
                string s;
                dfs(grid, i, j, n, m, s);
                mp[s] = 1;
            }
        }
        return mp.size();
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}

/* Sample Input
2
4 5
1 1 0 1 1
1 0 0 0 0
0 0 0 0 1
1 1 0 1 1
4 5
1 1 0 0 0
1 1 0 0 0
0 0 0 1 1
0 0 0 1 1

Sample Output
3
1

*/