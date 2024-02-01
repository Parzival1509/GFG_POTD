// GFG POTD 2024/01/29
// Count Digit Groupings of a Number
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int i, int prev, string &str, vector<vector<int>> &dp) {
        int n = str.length();
        if(i == n) return 1;
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int sum = 0, ans = 0;
        for(int ind = i; ind < n; ind++) {
            sum += (str[ind] - '0');
            if(sum >= prev)
                ans += rec(ind + 1, sum, str, dp);
        }
        
        return dp[i][prev] = ans;
    }
    
    int TotalCount(string str) {
        vector<vector<int>> dp(str.length(), vector<int> (1000, -1));
        return rec(0, 0, str, dp);
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.TotalCount(str);
        cout << ans <<"\n";
    }

    return 0;
}

/* Sample Input:
2
1119
12

Sample Output:
7
2

*/