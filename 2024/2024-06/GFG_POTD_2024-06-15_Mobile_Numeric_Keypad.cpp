// GFG POTD 2024/06/15
// Mobile Numeric Keypad
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getCount(int n) {
        if (n <= 0)
            return 0;

        long long dp[n + 1][10];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < 10; ++j)
                dp[i][j] = 0;

        vector<vector<int>> vec(10);
        vec[0] = {0, 8};
        vec[1] = {1, 2, 4};
        vec[2] = {1, 2, 3, 5};
        vec[3] = {2, 3, 6};
        vec[4] = {1, 4, 5, 7};
        vec[5] = {2, 4, 5, 6, 8};
        vec[6] = {3, 5, 6, 9};
        vec[7] = {4, 7, 8};
        vec[8] = {0, 5, 7, 8, 9};
        vec[9] = {6, 8, 9};

        for (int i = 0; i < 10; ++i)
            dp[1][i] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < 10; ++j)
                for (int prev : vec[j])
                    dp[i][j] += dp[i - 1][prev];

        long long sum = 0;
        for (int i = 0; i < 10; ++i)
            sum += dp[n][i];

        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.getCount(n) << endl;
    }
    return 0;
}

/* Sample Input
2
1
2

Sample Output
10
36

*/