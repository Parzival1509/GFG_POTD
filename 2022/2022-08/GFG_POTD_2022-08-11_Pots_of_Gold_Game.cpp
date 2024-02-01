#include <bits/stdc++.h>
using namespace std;

using Pii = pair<int, int>;
class Solution {
public:
    int maxCoins(vector<int>&A,int n) {
        Pii dp[n][n];
        memset(dp, 0, sizeof dp);
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = {A[i], 0};
        }
        
        for (int i = 2; i < n+1; i++) {
            for (int j = 0, k = i-1; k < n; j++, k++) {
                int c1 = A[j] + dp[j+1][k].second;
                int c2 = A[k] + dp[j][k-1].second;
                dp[j][k] = c1 > c2 ? make_pair(c1, dp[j+1][k].first) : make_pair(c2, dp[j][k-1].first);
            }
        }
        
        return dp[0][n-1].first;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}

/* Sample Input
1
4
8 15 3 7

Sample Output
22
*/