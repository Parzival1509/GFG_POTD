// GFG POTD 2023/09/16
// Counting Steps
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int x = 1000000007;
    
    long long countWays(int n) {
        // Approach 1: S.C. = O(N)
        vector<long long> dp(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            long long one = 0, two = 0, three = 0;
            
            one = dp[i - 1] % x;
            if(i > 1) two = dp[i - 2] % x;
            if(i > 2) three = dp[i - 3] % x;
            
            dp[i] = (one + two + three) % x;
        }
        
        return dp[n];
        
        // // Approach 2: S.C. = O(1)
        // long long a = 1, b = 2, c = 4;
        // if(n == 1 || n == 2) return n;
        // if(n == 3) return 4;
        
        // long long ans;
        // for(int i = 4; i <= n; i++) {
        //     ans = (a + b + c) % x;
        //     a = b;
        //     b = c;
        //     c = ans;
        // }
        
        // return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        Solution ob;
        cout << ob.countWays(n) << endl;
    }
    
    return 0;
}

/* Sample Input:
4
1 2 3 4

Sample Output:
1
2
4
7

*/