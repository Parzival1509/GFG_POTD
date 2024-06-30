// GFG POTD 2024/06/25
// Left Rotate Matrix K Times
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int rows = mat.size(), cols = mat[0].size();
        if (rows == 0 || cols == 0)
            return mat;

        k = k % cols;
        for (int i = 0; i < rows; i++) {
            vector<int> newRow(cols);
            for (int j = 0; j < cols; j++)
                newRow[j] = mat[i][(j + k) % cols];
            mat[i] = newRow;
        }

        return mat;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
 
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

/* Sample Input
2

3 3 1
1 2 3
4 5 6
7 8 9

3 3 2
1 2 3
4 5 6
7 8 9


Sample Output
2 3 1 
5 6 4 
8 9 7 

3 1 2 
6 4 5 
9 7 8 


*/