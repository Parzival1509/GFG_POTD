// GFG POTD 2023/08/21
// Surrounding the 1's
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m) {
        int ct = 0;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for(int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            
            if((x >= 0 && x < n) && (y >= 0 && y < m) && matrix[x][y] == 0)
                ct++;
        }
        
        return ct && (ct % 2 == 0);
    }

    int Count(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] && solve(matrix, i, j, n, m))
                    ans++;
                
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> matrix[i][j];

        Solution ob;
        int ans = ob.Count(matrix);
        cout << ans <<"\n";
    }
    return 0;
}

/* Sample Input:
2

3 3
1 0 0
1 1 0
0 1 0

1 1
1

Sample Output:
1
0

*/