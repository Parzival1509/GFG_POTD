#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool visited[105][105] ;
    bool possible(int i ,int j ,int n ,int m)
    {
        return i>=0 and j>=0 and i<n and j<m ;
    }
    
    void dfs(std::vector<std::vector<char>> &v,int i,int j,int n,int m)
    {
        if(!possible(i,j,n,m) || v[i][j] == 'O')return ;
        if(visited[i][j]) return ;
        visited[i][j] = true ;
        dfs(v,i,j+1,n,m) ;
        dfs(v,i,j-1,n,m) ;
        dfs(v,i-1,j,n,m) ;
        dfs(v,i+1,j,n,m) ;
    }

    int xShape(vector<vector<char>>& grid) 
    {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int ct = 0 ;
        memset(visited,false,sizeof visited) ;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(!visited[i][j] and grid[i][j] == 'X')
                {
                    dfs(grid,i,j,n,m) ;
                    ct++ ;
                }
        return ct ;
    }

};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>>grid(n, vector<char>(m, '#'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.xShape(grid);
        cout << ans <<'\n';
    }
    return 0;
}