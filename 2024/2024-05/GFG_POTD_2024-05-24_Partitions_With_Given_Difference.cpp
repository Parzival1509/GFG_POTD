// GFG POTD 2024/05/24
// Partitions with Given Difference
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0), mod = 1e9 + 7;

        if ((sum + d) & 1)
            return 0;

        int s1 = (sum + d) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= s1; j++) {
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
            }

        return dp[n][s1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}

/* Sample Input
2
4 3
5 2 6 4
4 0
1 1 1 1

Sample Output
1
6

*/