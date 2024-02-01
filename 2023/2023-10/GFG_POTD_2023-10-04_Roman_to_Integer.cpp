// GFG POTD 2023/10/04
// Roman to Integer
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToDecimal(string &str) {
        map<char, int> val;
        val.insert({'I', 1});
        val.insert({'V', 5});
        val.insert({'X', 10});
        val.insert({'L', 50});
        val.insert({'C', 100});
        val.insert({'D', 500});
        val.insert({'M', 1000});
        
        int ans = 0, n = str.size(), prev = 0;
        for(int i = 0; i < n - 1; i++) {
            if(val[str[i]] < val[str[i + 1]])
                prev = val[str[i]];
            else {
                ans += val[str[i]] - prev;
                prev = 0;
            }
        }
        ans += val[str[n - 1]] - prev;
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}

/* Sample Input:
4
III
V
XIX
CXLIV

Sample Output:
3
5
19
144

*/