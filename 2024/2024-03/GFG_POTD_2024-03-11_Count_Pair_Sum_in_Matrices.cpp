// GFG POTD 2024/03/11
// Count Pair Sum in Matrices
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n, int x) {
        int row1 = 0, col1 = 0, row2 = n - 1, col2 = n - 1, count = 0;

        while (row1 < n && row2 > -1) {
            int sum = mat1[row1][col1] + mat2[row2][col2];

            if (sum == x) {
                count++;
                col1++;
                col2--;
            } else if (sum < x)
                col1++;
            else col2--;

            if (col1 == n) {
                row1++;
                col1 = 0;
            }
            if (col2 == -1) {
                row2--;
                col2 = n - 1;
            }
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> mat1(n, vector<int>(n, -1)), mat2(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat1[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat2[i][j];
        
        Solution ob;
        cout << ob.countPairs(mat1, mat2, n, x) << endl;
    }

    return 0;
}

/* Sample Input
2

3 21
1 5 6
8 10 11
15 16 18
2 4 7
9 10 12
13 16 20

2 10
1 2
3 4
4 5
6 7

Sample Output
4
2

*/