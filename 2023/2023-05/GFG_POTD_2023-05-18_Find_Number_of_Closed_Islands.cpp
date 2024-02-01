// GFG POTD 2023/05/18
// Find Number of Closed Islands
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &matrix) {
        if(i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size() || matrix[i][j] == 0)
            return;
        
        matrix[i][j] = 0;
        dfs(i+1, j, matrix);
        dfs(i-1, j, matrix);
        dfs(i, j+1, matrix);
        dfs(i, j-1, matrix);
    }

    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if((i == 0 || i == N-1 || j == 0 || j == M-1) && matrix[i][j] == 1)
                    dfs(i, j, matrix);
        
        int ans = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(matrix[i][j] == 1) {
                    ans++;
                    dfs(i, j, matrix);
                }
    
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input:
2
5 8
0 0 0 0 0 0 0 1 
0 1 1 1 1 0 0 1 
0 1 0 1 0 0 0 1 
0 1 1 1 1 0 1 0 
0 0 0 0 0 0 0 1
3 3
1 0 0
0 1 0
0 0 1

Sample Output:
2
1

*/