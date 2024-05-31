// GFG POTD 2024/05/29
// Geek and its Game of Coins
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int x, int y, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int take1 = 0, take2 = 0, take3 = 0;
        if (n >= x)
            take1 = 1 + solve(n - x, x, y, dp);
        if (n >= y)
            take2 = 1 + solve(n - y, x, y, dp);

        take3 = 1 + solve(n - 1, x, y, dp);
        if (take1 % 2 == 1 || take2 % 2 == 1 || take3 % 2 == 1)
            return dp[n] = 1;
        
        return dp[n] = 0;
    }

    int findWinner(int n, int x, int y) {
        vector<int> dp(n + 1, -1);
        return solve(n, x, y, dp);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << ob.findWinner(n, x, y) << endl;
    }
    return 0;
}

/* Sample Input
2
5 3 4
2 3 4

Sample Output
1
0

*/