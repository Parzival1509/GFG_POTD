// GFG POTD 2023/12/15
// Reach the Nth Point
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthPoint(int n) {
        if(n == 0 || n == 1) return 1;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
            
        return dp[n];
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans  = ob.nthPoint(n);
        cout << ans <<"\n";
    }

    return 0;
}

/* Sample Input:
2
4
5

Sample Output:
5
8

*/