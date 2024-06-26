// GFG POTD 2024/03/27
// Find Shortest Safe Route in a Matrix
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 2 || i - 1 >= 0 && mat[i - 1][j] == 0 || i + 1 < n && mat[i + 1][j] == 0 || j - 1 >= 0 && mat[i][j - 1] == 0 || j + 1 < m && mat[i][j + 1] == 0)
            return 1e6;

        if (j == m - 1)
            return 1;

        mat[i][j] = 2;
        int left = dfs(i - 1, j, mat);
        int right = dfs(i + 1, j, mat);
        int up = dfs(i, j - 1, mat);
        int down = dfs(i, j + 1, mat);
        mat[i][j] = 1;

        return 1 + min(min(left, right), min(up, down));
    }

    int findShortestPath(vector<vector<int>>& mat) {
        int ans = INT_MAX;
        for (int i = 0; i < mat.size(); i++)
            if (mat[i][0])
                ans = min(ans, dfs(i, 0, mat));

        return (ans >= 1e6) ? -1 : ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> mat[i][j];
        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2

5 5
1 0 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 0 1
1 1 1 1 0

3 5
1 1 1 1 1
1 1 0 1 1
1 1 1 1 1


Sample Output
6
-1

*/