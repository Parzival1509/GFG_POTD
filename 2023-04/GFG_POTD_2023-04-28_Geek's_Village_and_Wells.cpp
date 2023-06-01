// GFG POTD 2023/04/28
// Geek's Village and Wells
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool inrange(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
        int dx[] = {1 , 0, -1, 0};
        int dy[] = {0 , 1, 0, -1};
        
        vector<vector<int>> res(n, vector<int> (m, -1));
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i =  0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(c[i][j] == 'W') {
                    q.push({{i, j}, 0});
                    res[i][j] = 0;
                }

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0 ; i < sz; i++) {
                auto x = q.front();
                q.pop();
                int u = x.first.first;
                int v = x.first.second;
                int dis = x.second;
                for(int j = 0; j < 4; j++) {
                    int newx = u + dx[j];
                    int newy = v + dy[j];
                    if(inrange(newx, newy, n, m) && c[newx][newy] != 'N' && !vis[newx][newy] && c[newx][newy]!='W') {
                        q.push({{newx, newy}, dis + 2});
                        res[newx][newy] = dis + 2;
                        vis[newx][newy] = true;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(c[i][j] != 'H')
                    res[i][j] = 0;
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<char>> c(n, vector<char>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin>>c[i][j];
        Solution ob;
        vector<vector<int>> res = ob.chefAndWells(n, m, c);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}

/* Sample Input:
2

3 3
H H H
H W H
H H H

5 5
H N H H H
N N H H W
W H H H H
H H H H H
H H H H H

Sample Output:
4 2 4 
2 0 2 
4 2 4 

-1 0 6 4 2 
0 0 4 2 0 
0 2 4 4 2 
2 4 6 6 4 
4 6 8 8 6 


*/