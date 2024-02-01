// GFG POTD 2023/09/17
// Print First N Fibonacci Numbers
// Basic

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> printFibb(int n) {
        vector<long long> dp(n, 0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Solution obj;
        vector<long long> ans = obj.printFibb(n);
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
2
5 7

Sample Output:
1 1 2 3 5 
1 1 2 3 5 8 13 

*/