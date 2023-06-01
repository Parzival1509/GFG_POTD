// GFG POTD 2023/03/20
// Shortest XY Distance in Grid
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force Approach
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        vector<pair<int, int>>X, Y;
        
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++) {
                if(grid[i][j] == 'X') X.push_back({i, j});
                if(grid[i][j] == 'Y') Y.push_back({i, j});
            }

        int ans = INT_MAX;
        for(int i=0; i<X.size(); i++)
            for(int j=0; j<Y.size(); j++) {
                ans = min(ans, abs(X[i].first-Y[j].first) + abs(Y[j].second-X[i].second));
                if(ans == 1) return ans;
            }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;
        vector<vector<char>> grid;
        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }
        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}

/* Sample Input:
2
3 3
X X 0
0 0 Y
Y 0 0
4 4
X 0 0 0
0 Y 0 Y
X X 0 0
0 Y 0 0

Sample Output:
2
1

*/