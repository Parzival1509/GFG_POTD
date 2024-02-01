//GFG POTD Unit Area of Largest Region of 1's
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool visited[501][501];
    bool checkPos(int i , int j , vector<vector<int>> &grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()){
            return true;
        }
        return false;
    }
    
    void dfs(int i,int j,vector<vector<int>> &grid , int &res){
        
        if(!checkPos(i,j,grid) || grid[i][j] == 0) return;
        
        if(visited[i][j]) return;
        
        visited[i][j] = 1;
        
        res++;
        dfs(i,j-1,grid,res);
        dfs(i,j+1,grid,res);
        dfs(i-1,j,grid,res);
        dfs(i+1,j,grid,res);
        dfs(i-1,j-1,grid,res);
        dfs(i+1,j-1,grid,res);
        dfs(i-1,j+1,grid,res);
        dfs(i+1,j+1,grid,res);
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        memset(visited , 0 , sizeof visited);
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int mx = INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int res = 0;
                    dfs(i,j,grid,res);
                    mx = max(res,mx);
                }
            }
        }
        
        if(mx == INT_MIN){
            return 0;
        }
        return mx;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
/* Sample Input
2 2

Sample Output

*/