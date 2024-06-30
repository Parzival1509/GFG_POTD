// GFG POTD 2024/06/26
// Coverage of all Zeros in a Binary Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), coverage = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (j > 0 && matrix[i][j - 1] == 1)
                        coverage++;
                    if (j < m - 1 && matrix[i][j + 1] == 1)
                        coverage++;
                    if (i > 0 && matrix[i - 1][j] == 1)
                        coverage++;
                    if (i < n - 1 && matrix[i + 1][j] == 1)
                        coverage++;
                }
            }
        
        return coverage;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << endl;
    }
    return 0;
}

/* Sample Input
2
1 2
0 1
3 3
0 1 0
0 1 1
0 0 0

Sample Output
1
6

*/