// GFG POTD 2024/04/07
// Maximize Dot Product
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];

    int func(int i, int j, int& n, int& m, int a[], int b[]) {
        if (j == m) return 0;
        if (i == n) return -1e7;
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = max((a[i] * b[j]) + func(i + 1, j + 1, n, m, a, b), func(i + 1, j, n, m, a, b));
    }

    int maxDotProduct(int n, int m, int a[], int b[]) {
        memset(dp, -1, sizeof(dp));
        return func(0, 0, n, m, a, b);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxDotProduct(n, m, a, b) << "\n";
    }

    return 0;
}

/* Sample Input
2
5 3
2 3 1 7 8
3 6 7
3 1
1 2 3
4

Sample Output
107
12

*/