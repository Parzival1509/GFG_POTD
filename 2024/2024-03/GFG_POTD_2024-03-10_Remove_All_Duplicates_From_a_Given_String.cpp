// GFG POTD 2024/03/10
// Remove All Duplicates From a Given String
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string str) {
        unordered_set<char> s;
        string ans = "";
        
        for(int i = 0; i < str.length(); i++)
            if(s.find(str[i]) == s.end()) {
                ans.push_back(str[i]);
                s.insert(str[i]);
            }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
geEksforGEeks
HaPpyNewYear

Sample Output
geEksforG
HaPpyNewYr

*/