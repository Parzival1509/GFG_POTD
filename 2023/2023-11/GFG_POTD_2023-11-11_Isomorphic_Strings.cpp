// GFG POTD 2023/11/11
// Isomorphic Strings
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areIsomorphic(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;

        unordered_map<char, char> mp1, mp2;
        for(int i = 0; i < s1.size(); i++) {
            if(mp1.find(s1[i]) == mp1.end() && mp2.find(s2[i]) == mp2.end()) {
                mp1[s1[i]] = s2[i];
                mp2[s2[i]] = s1[i];
            }
            else if(mp1.find(s1[i]) != mp1.end() && mp2.find(s2[i]) != mp2.end()) {
                if(mp1[s1[i]] != s2[i]) return false;
            }
            else return false;
        }

        return true;
    }
};

int main() {
    int t;
    cin >> t;
    string s1,s2;
    while(t--) {
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
aab xxy
aab xyz
pijthbsfy fvladzpbf

Sample Output:
1
0
0

*/