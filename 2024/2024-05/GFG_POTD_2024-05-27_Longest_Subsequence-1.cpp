// GFG POTD 2024/05/27
// Longest Subsequence-1
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubseq(int n, vector<int>& a) {
        map<int, int> dp;
        int ans = 1;

        for (size_t i = 0; i < n; i++) {
            dp[a[i]] = max(dp[a[i]], 1);

            if (dp.count(a[i] - 1))
                dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);

            if (dp.count(a[i] + 1))
                dp[a[i]] = max(dp[a[i]], dp[a[i] + 1] + 1);

            ans = max(ans, dp[a[i]]);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for(int &i: a)
            cin >> i;
        cout << ob.longestSubseq(n, a) << endl;
    }
    return 0;
}

/* Sample Input
2
7
10 9 4 5 4 8 6
5
1 2 3 4 5

Sample Output
3
5

*/