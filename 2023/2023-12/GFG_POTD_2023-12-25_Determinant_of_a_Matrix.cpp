// GFG POTD 2023/12/25
// Determinant of a Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int determinantOfMatrix(vector<vector<int>> matrix, int n) {
        if(n == 1) return matrix[0][0];
        if(n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

        int total = 0;
        vector<vector<int>> mat(n - 1, vector<int>(n - 1, 0));
        
        for(int i = 0; i < n; i++) {
            for(int row = 1; row < n; row++) {
                int col_i = 0;
                for(int col = 0; col < n; col++) {
                    if(col == i) continue;
                    mat[row - 1][col_i++] = matrix[row][col];
                }
            }
            
            total += ((i % 2 == 0)? 1: -1) * matrix[0][i] * determinantOfMatrix(mat, n - 1);
        }
        
        return total;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n); 
        for(int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for( int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout << result << endl;
    }
    
    return 0;
}

/* Sample Input:
2
4
1 0 2 -1
3 0 0 5
2 1 4 -3
1 0 5 0
3
1 2 3
4 5 6
7 10 9

Sample Output:
30
12

*/