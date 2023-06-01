// GFG POTD 2023/01/23
// Geeks And The String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removePair(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++)
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        if(ans.size() == 0) return "-1";
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s; 
        cin>>s;
        Solution obj;
        string res = obj.removePair(s);
        cout<<res<<endl;
    }
}

/* Sample Input
2
aaabbaaccd
aaaa

Sample Output
ad
-1

*/