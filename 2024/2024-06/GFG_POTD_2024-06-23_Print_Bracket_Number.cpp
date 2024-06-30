// GFG POTD 2024/06/23
// Print Bracket Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bracketNumbers(string str) {
        stack<int> st;
        int count = 0;
        vector<int> ans;

        for (int i = 0; i < str.length(); i++)
            if (str[i] == '(') {
                count++;
                st.push(count);
                ans.push_back(st.top());
            } else if (str[i] == ')') {
                ans.push_back(st.top());
                st.pop();
            }

        return ans;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        vector<int> ans = ob.bracketNumbers(s);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
(aa(bdc))p(dee)
(((()(

Sample Output
1 2 2 1 3 3 
1 2 3 4 4 5 

*/