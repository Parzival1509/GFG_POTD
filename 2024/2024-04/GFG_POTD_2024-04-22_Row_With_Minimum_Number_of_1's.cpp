// GFG POTD 2024/04/22
// Row with Minimum Number of 1's
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int row = 0, s = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = accumulate(a[i].begin(), a[i].end(), 0);
            if (sum < s) {
                s = sum;
                row = i;
            }
        }

        return row + 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}

/* Sample Input
2
4 4
1 1 1 0
1 1 0 0
0 0 1 1
1 1 1 1
3
0 0 0
0 0 0
0 0 0

Sample Output
2
1

*/