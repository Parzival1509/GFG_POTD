// GFG POTD 2024/03/13
// Print Matrix in Diagonal Pattern
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> res(n * n);

        // Upper Triangular
        int z = 0;
        for (int i = 0; i < n; i++) {
            int j = 0, k = i;
            for (int m = 0; m <= i; m++) {
                if (i % 2 == 0)
                    res[z++] = mat[k][j];
                else res[z++] = mat[j][k];
                k--;
                j++;
            }
        }

        // Lower Triangular
        z = n * n - 1;
        for (int i = n - 1, p = 0; i > 0; i--, p++) {
            int j = n - 1, k = i;
            for (int m = i; m < n; m++) {
                if (p % 2 == 0)
                    res[z--] = mat[k][j];
                else res[z--] = mat[j][k];
                k++;
                j--;
            }
        }

        return res;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        int k = 0;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}

/* Sample Input
2
2
1 2
3 4
3
1 2 3
4 5 6
7 8 9

Sample Output
1 2 3 4 
1 2 4 7 5 3 6 8 9 

*/