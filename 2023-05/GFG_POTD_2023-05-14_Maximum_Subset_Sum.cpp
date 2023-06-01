// GFG POTD 2023/05/14
// Maximum Subset Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll findMaxSubsetSum(int n, vector<int> &a) {
        ll ans = 0;
        vector<pair<ll, ll>> dp(n, {0, 0});
        dp[0].first = a[0];
        dp[0].second = 0;
        for(int i=1; i<n; i++) {
            dp[i].first = a[i] + max(dp[i-1].first, dp[i-1].second);
            dp[i].second = dp[i-1].first;
        }
        return max(dp[n-1].first, dp[n-1].second);
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n, 0);
        for(int &i: a)
            cin>>i;
        Solution ob;
        cout<<ob.findMaxSubsetSum(n, a)<<endl;
    }
}

/* Sample Input:
2
3
0 2 0
4
1 -1 3 4

Sample Output:
2
8

*/