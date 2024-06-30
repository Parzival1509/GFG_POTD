// GFG POTD 2024/06/01
// Odd Even Problem
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string oddEven(string s) {
        vector<int> ct(26, 0);
        for(int i = 0; i < s.size(); i++)
            ct[s[i] - 'a']++;
        
        int x = 0, y = 0;
        for(int i = 1; i <= 26; i++)
            if((i & 1) && (ct[i - 1] & 1))
                x++;
            else if((!(i & 1)) && (!(ct[i - 1] & 1)) && ct[i - 1] != 0)
                y++;
        
        return ((x + y) & 1)? "ODD": "EVEN";
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        string s;
        cin >> s;
        cout << ob.oddEven(s) << endl;
    }
    return 0;
}

/* Sample Input
4
abbbcc
nobitaa
dgamrakmk
bddvpw

Sample Output
ODD
EVEN
ODD
EVEN

*/