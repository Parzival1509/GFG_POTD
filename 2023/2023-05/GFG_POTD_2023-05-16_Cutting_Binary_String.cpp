// GFG POTD 2023/05/16
// Cutting Binary String
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Approach 1: DP Memoization
    bool check_number(int n) {
        while(n >= 5) {
            if(n % 5 != 0) return false;
            n /= 5;
        }
        return n == 1;
    }

    int solve(int i, ll number, string &s, vector<unordered_map<ll, int>> &dp) {
        if(i == s.size()) {
            if (number == 0) return 0;
            return 1e9;
        }

        if(number == 0 && s[i] == '0') return 1e9;
        
        if(dp[i].find(number) != dp[i].end())
            return dp[i][number];

        number = (number << 1) + (s[i] - '0');
        int ans = solve(i + 1, number, s, dp);
        if(check_number(number))
            ans = min(ans, (1 + solve(i + 1, 0, s, dp)));

        return dp[i][number] = ans;
    }
    
    int cuts(string s) {
        vector<unordered_map<ll, int>> dp(s.length() + 1);
        int ans = solve(0, 0ll, s, dp);
        return (ans >= 1e9)? -1: ans;
    }

    // // Approach 2:
    // bool isPowerOfFive(string s) {
    //     int n = s.length();
    //     if(n == 0) return false;
    //     if(s[0] == '0') return false; 
        
    //     ll num = 0;
    //     for(int i = 0; i < n; i++)
    //         num = num * 2 + (s[i] - '0');
        
    //     if(num == 0) return false;  
    //     while(num > 1) {
    //         if(num % 5 != 0) return false;
    //         num /= 5;
    //     }
    //     return true;
    // }
    
    // int cuts(string s) {
    //     int n = s.length();
    //     if(n == 0 || s[0] == '0') return -1;
    //     if(isPowerOfFive(s)) return 1;
        
    //     int minCuts = INT_MAX;
    //     for(int i = 1; i < n; i++) {
    //         string left = s.substr(0, i);
    //         string right = s.substr(i);
    //         if(isPowerOfFive(left)) {
    //             int cutsRight = cuts(right);
    //             if(cutsRight != -1)
    //                 minCuts = min(minCuts, 1 + cutsRight);
    //         }
    //     }
        
    //     if(minCuts != INT_MAX) return minCuts;
    //     return -1; 
    // }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.cuts(s)<<endl;
    }
}

/* Sample Input:
2
101101101
00000

Sample Output:
3
-1

*/