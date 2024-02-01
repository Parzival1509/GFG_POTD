// GFG POTD 2023/12/28
// Wildcard String Matching
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(string wild, string pattern) {
        int n = wild.length(), m = pattern.length();
        int i = 0, j = 0;
        
        for(; j < m; j++) {
            if(wild[i] == '?') {
                i++;
                continue;
            }
            else if(wild[i] == '*') {
                i++;
                j++;
                
                while(i<n && (wild[i] == '*' || wild[i] == '?')) {
                    i++;
                    j++;
                }
                while(j<m && wild[i]!=pattern[j])
                    j++;
                i++;
                continue;
            }
            else if(wild[i] != pattern[j])
                return false;
            i++;
        }
        
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string wild, pattern;
        cin >> wild >> pattern;
        Solution ob;
        bool x = ob.match(wild, pattern);
        if(x) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

/* Sample Input:
2
ge*ks
ge?ks*

Sample Output:
No
Yes

*/