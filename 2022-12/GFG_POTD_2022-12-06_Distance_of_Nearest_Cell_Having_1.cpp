// GFG POTD 2022/12/06
// Distance of Nearest Cell Having 1
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j]) 
                    q.push({i, j});

       vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
       
       int level = 0;
       while(!q.empty()) {
           int sz = q.size();
           while(sz --) {
               int x = q.front().first;
               int y = q.front().second;
               q.pop();
               
               if(res[x][y] != -1) continue;
               res[x][y] = level;
               
               for(auto it: dirs) {
                   int nx = x + it.first;
                   int ny = y + it.second;
                   
                   if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                       q.push({nx, ny});
               }
           }
           level++;
       }
       return res;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for(auto i: ans){
            for(auto j: i)
                cout << j << " ";
            cout << endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
3 4
0 1 1 0
1 1 0 0
0 0 1 1
3 3
1 0 1
1 1 0
1 0 0

Sample Output
1 0 0 1 
0 0 1 1 
1 1 0 0 

0 1 0 
0 0 1 
0 1 2 


*/