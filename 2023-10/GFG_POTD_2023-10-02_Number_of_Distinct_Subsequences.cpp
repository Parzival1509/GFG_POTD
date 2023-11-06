// GFG POTD 2023/10/02
// Number of Distinct Subsequences
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubsequences(string s) {
        int ans = 1, diff = 0, mod = 1e9 + 7;
        int hsh[26] = {-1};
        
        // First character will have only one subsequence other than empty one
        hsh[s[0] - 'a'] = 1;
        
        for(int i = 1; i < s.size(); i++) {
            // No. of subsequences till (i - 1)th element
            diff = 1 + ans;
            int x = s[i] - 'a';
            
            // No. of subsequences till ith element
            ans = (ans + diff) % mod;
            
            // Checking for already occured subsequences and subtracting them
            if(hsh[x] != -1) ans = (ans - hsh[x]) % mod;
            
            hsh[x] = diff;
        }
        
        ans++;  // For empty subsequence
        
        return (ans < 0)? (ans + mod): ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.distinctSubsequences(s) << "\n";
    }

    return 0;
}

/* Sample Input:
2
gfg
ggg

Sample Output:
7
4

*/