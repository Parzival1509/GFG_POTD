// GFG POTD 2022/12/02
// Check if it is possible to convert one string into another with given constraints

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isItPossible(string s, string t, int m, int n) {
        if(m!=n) return 0;
        vector<int> ss, tt;
        for(int i=0; i<m; i++) {
            if(s[i]!='#') ss.push_back(i);
            if(t[i]!='#') tt.push_back(i);
        }
        if(ss.size()!=tt.size()) return 0;
        for(int i=0; i<ss.size(); i++) {
            if(s[ss[i]] != t[tt[i]]) return 0;
            if(s[ss[i]]=='A' && ss[i]<tt[i]) return 0;
            if(s[ss[i]]=='B' && ss[i]>tt[i]) return 0;
        }
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}

/* Sample Input
3
#A#B# #B#A#
#A#B#B# A###B#B
ABB ABB

Sample Output
0
1
1

*/