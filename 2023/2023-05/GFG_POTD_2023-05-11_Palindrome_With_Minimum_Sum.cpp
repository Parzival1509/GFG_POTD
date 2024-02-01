// GFG POTD 2023/05/11
// Palindrome With Minimum Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(string s) {
        int n = s.length(), l = 0, r = n-1, ans = 0;
        while(l < r) {
            if(s[l] == '?' && s[r] != '?') s[l] = s[r];
            else if(s[l] != '?' && s[r] == '?') s[r] = s[l];
            else if(s[l] != '?' && s[r] != '?' && s[l] != s[r]) return -1;
            l++;
            r--;
        }
        
        l = 0;
        while(l <= n/2 && s[l] == '?') l++;
        s[max(l-1, 0)] = s[l];
        
        while(l <= n/2) {
            if(s[l] == '?') s[l] = s[l-1];
            else if(l > 0) ans += abs(s[l] - s[l-1]);
            l++;
        }
        return 2 * ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

/* Sample Input:
3
???a????
a???c??c????
a???c??c???c

Sample Output:
0
4
-1

*/