// GFG POTD 2023/02/03
// Last Cell in a Matrix
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> endPoints(vector<vector<int>> mat, int r, int c) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ct = 0, x = 0, y = 0;
        while(x>=0 and x<r and y>=0 and y<c) {
            if(mat[x][y] == 1) {
                mat[x][y] = 0;
                ct = (ct+1)%4;
            }
            x += dir[ct].first;
            y += dir[ct].second;
        }
        return {x-dir[ct].first, y-dir[ct].second};
    }
};

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        int row, col;
        cin>>row>>col;
        vector<vector<int>> matrix(row, vector<int> (col));
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>matrix[i][j];
        Solution obj;
        pair<int, int> p = obj.endPoints(matrix, row, col);
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}

/* Sample Input:
3
2 2
0 1
1 0
3 5
0 1 1 1 0
1 0 1 0 1
1 1 1 0 0
3 2
1 0
0 1
1 0

Sample Output:
(1, 1)
(2, 0)
(2, 0)

*/