// GFG POTD 2023/02/25
// Valid Compressed String
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkCompressed(string s, string t) {
        int i = 0, j = 0, ct = 0;

        for(i=0; i<t.size(); i++) {
            char ch = t[i];
            // cout<<ch<<' '<<i<<' '<<j<<' '<<ct<<endl;
            if(ch >= 'A' && ch <= 'Z') {
                j += ct;
                if(j >= s.size() || ch != s[j])
                    return 0;
                j++;
                ct = 0;
            }
            else ct = ct*10 + (ch-'0');
            // cout<<ch<<' '<<i<<' '<<j<<' '<<ct<<endl<<endl;
        }
        j += ct-1;
        // cout<<i<<' '<<j<<' '<<ct<<endl<<endl;
        if(j >= s.size()) return 0;
        return 1;
    }
};

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        string S, T;
        cin>>S>>T;
        Solution ob;
        cout << ob.checkCompressed(S, T) << endl;
    }
    return 0;
}

/* Sample Input:
3
GEEKSFORGEEKS G7G3S
DFS D1D
IXVGJREVJ 3GJR4

Sample Output:
1
0
0

*/