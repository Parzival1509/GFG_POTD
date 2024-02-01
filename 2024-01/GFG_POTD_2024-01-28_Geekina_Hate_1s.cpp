// GFG POTD 2024/01/28
// Geekina Hate 1s
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    struct Triple {
        ll x, y, z;
        Triple(ll a, ll b, ll c) : x(a), y(b), z(c) {}
    };

    vector<vector<vector<ll>>> dp;

    ll find(ll n, int k) {
        string s = bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }

    ll dpf(string& s, int n, int tight, int k) {
        if (k < 0) return 0;
        if (n == 0) return 1;
        if (dp[tight][k][n] != -1)
            return dp[tight][k][n];
        
        int ub = (tight == 1 ? s[s.length() - n] - '0' : 1);
        ll ans = 0;
        for (int dig = 0; dig <= ub; dig++)
            if (dig == ub)
                ans += dpf(s, n - 1, tight, k - dig);
            else ans += dpf(s, n - 1, 0, k - dig);
        
        return dp[tight][k][n] = ans;
    }

    void reset() {
        for (int i = 0; i < 65; i++)
            for (int j = 0; j < 65; j++) {
                dp[0][i][j] = -1;
                dp[1][i][j] = -1;
            }
    }
    
    ll findNthNumber(int n, int k) {
        ll low = 0, high = 1e18;
        dp.resize(2, vector<vector<ll>>(65, vector<ll>(65)));
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll count = find(mid, k);
            if (count >= n)
                high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        Solution obj;
        ll res = obj.findNthNumber(n, k);
        cout << res << endl;        
    }
}

/* Sample Input:
2
5 1
6 2

Sample Output:
8
5

*/