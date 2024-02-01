// GFG POTD 2024/01/03
// Smallest Window Containing 0, 1 and 2
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubstring(string s) {
        int lo = 0, hi = 0, ans = INT_MAX;
        int z = 0, o = 0, t = 0;
        
        while(hi < s.size()) {
            if(s[hi] - '0' == 0) z++;
            else if(s[hi] - '0' == 1) o++;
            else t++;
            
            while(z && o && t) {
                ans = min(ans, hi - lo + 1);
                
                if(s[lo] - '0' == 0) z--;
                else if(s[lo] - '0' == 1) o--;
                else t--;
                
                lo++;
            }
            hi++;
        }
        
        return (ans == INT_MAX)? -1: ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S) << endl;
    }
}

/* Sample Input:
3
1210
10212
12121

Sample Output:
3
3
-1

*/