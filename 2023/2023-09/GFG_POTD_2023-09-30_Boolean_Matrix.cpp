// GFG POTD 2023/09/30
// Boolean Matrix
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {   
public:
    void booleanMatrix(vector<vector<int>> &matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> rows(r, 0), cols(c, 0);
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(matrix[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(rows[i] || cols[j])
                    matrix[i][j] = 1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row); 
        for(int i = 0; i < row; i++) {
            matrix[i].assign(col, 0);
            for( int j = 0; j < col; j++)
                cin >> matrix[i][j];
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

2 2
1 0
0 0

4 3
1 0 0
1 0 0
1 0 0
0 0 0

Sample Output:
1 0 
0 0 

1 0 0 
1 0 0 
1 0 0 
0 0 0 


*/