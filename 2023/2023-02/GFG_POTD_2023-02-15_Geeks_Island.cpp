// GFG POTD 2023/02/15
// Geeks Island
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {   
public:
    int N, M;

    void dfs(int i,int j, vector<vector<bool>> &vis, vector<vector<int>> &a) {
        if(i>=a.size() || j>=a[0].size() || i<0 || j<0 || vis[i][j]) return;
        
        vis[i][j] = 1;
        if(i+1<N && a[i][j]<=a[i+1][j]) dfs(i+1, j, vis, a);
        if(j+1<M && a[i][j]<=a[i][j+1]) dfs(i, j+1, vis, a);
        if(i-1>=0 && a[i][j]<=a[i-1][j]) dfs(i-1, j, vis, a);
        if(j-1>=0 && a[i][j]<=a[i][j-1]) dfs(i, j-1, vis, a);
    }
    
    int water_flow(vector<vector<int>> &a, int n, int m) {
        N = n, M = m;
        vector<vector<bool>> indian(n+2, vector<bool> (m+2, false));
        vector<vector<bool>> arabian(n+2, vector<bool> (m+2, false));

        // Indian
        for(int i=0; i<n; i++) dfs(i, 0, indian, a);
        for(int i=0; i<m; i++) dfs(0, i, indian, a);

        // Arabian
        for(int i=0; i<n; i++) dfs(i, m-1, arabian, a);
        for(int i=0; i<m; i++) dfs(n-1 ,i, arabian, a);

        int ans = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(indian[i][j] && arabian[i][j]) ans += 1;

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin>>mat[i][j];
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}

/* Sample Input:
2
5 5
1 3 3 2 4
4 5 6 4 4
2 4 5 3 1
6 7 1 4 5
6 1 1 3 4
2 3
1 1 1
1 1 1

Sample Output:
8
6

*/