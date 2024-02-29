// GFG POTD 2024/02/26
// Power Set
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void func(string s, int ind, string tempS) {
        if (ind == s.length()) {
            if (tempS != "")
                ans.push_back(tempS);
            return;
        }

        func(s, ind + 1, tempS);
        func(s, ind + 1, tempS + s[ind]);
    }

    vector<string> AllPossibleStrings(string s) {
        func(s, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}

/* Sample Input
2
aa
abc

Sample Output
a a aa 
a ab abc ac b bc c 

*/