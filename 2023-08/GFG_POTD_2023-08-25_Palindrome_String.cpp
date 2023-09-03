// GFG POTD 2023/08/25
// Palindrome String
// Easy
 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int isPalindrome(string s) {
        // string st = s;
        // reverse(st.begin(), st.end());
        // return s == st;
        
        for(int i = 0; i < s.size() / 2; i++)
            if(s[i] != s[s.size() - 1 - i])
                return 0;
                
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isPalindrome(s) << "\n";
    }
    return 0;
}

/* Sample Input:
2
abba
abc

Sample Output:
1
0

*/