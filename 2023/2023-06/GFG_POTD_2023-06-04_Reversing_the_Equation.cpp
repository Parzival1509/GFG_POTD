// GFG POTD 2023/06/04
// Reversing the Equation
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseEqn(string s) {
        stack<string> st;
        string tmp = "";
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch >= '0' && ch <= '9')
                tmp += ch;
            else {
                st.push(tmp);
                st.push(string(1, ch));
                tmp = "";
            }
        }
        st.push(tmp);
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseEqn(s) << endl;
    }
}

/* Sample Input:
2
20-3+5*2
5+2*56-2/4

Sample Output:
2*5+3-20
4/2-56*2+5

*/