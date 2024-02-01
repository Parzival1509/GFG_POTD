// GFG POTD 2023/11/15
// Better String
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueSubsequences(string &s) {
        int n = s.size(); 
        vector<int> dp(n + 1, 0);
        unordered_map<char, int> mp;
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
            if(mp.find(s[i - 1]) != mp.end()) {
                int index = mp[s[i - 1]];
                dp[i] -= dp[index - 1];
            }
            mp[s[i - 1]] = i;
        }
        
        return dp[n];
    }
    
    string betterString(string str1, string str2) {
        return uniqueSubsequences(str1) >= uniqueSubsequences(str2)? str1: str2;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

/* Sample Input:
2
gfg ggg
a b

Sample Output:
gfg
a

*/