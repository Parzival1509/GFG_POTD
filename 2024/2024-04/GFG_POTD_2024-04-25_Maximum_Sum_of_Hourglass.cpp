// GFG POTD 2024/04/25
// Maximum Sum of Hourglass
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                mat[i][j] += mat[i][j - 1];

        for (int i = 0; i <= (n - 3); i++)
            for (int j = 2; j < m; j++) {
                if (j - 3 >= 0)
                    ans = max(ans, mat[i][j] + mat[i + 2][j] - mat[i][j - 3] - mat[i + 2][j - 3] + mat[i + 1][j - 1] - mat[i + 1][j - 2]);
                else
                    ans = max(ans, mat[i][j] + mat[i + 2][j] + mat[i + 1][j - 1] - mat[i + 1][j - 2]);
            }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++)
                cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}

/* Sample Input
2
2 3
1 2 3
4 5 6
3 3
1 2 3
4 5 6
7 8 9

Sample Output
-1
35

*/