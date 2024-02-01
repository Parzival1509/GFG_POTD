// GFG POTD Geek and Number String
#include<bits/stdc++.h>
using namespace std; 

class Solution{
public:
    int minLength(string s, int n) {
        stack<char> st;
        st.push(s[0]);
        vector<int> v;
        v.push_back(9);
        v.push_back(2);
        v.push_back(1);
        v.push_back(4);
        v.push_back(3);
        v.push_back(6);
        v.push_back(5);
        v.push_back(8);
        v.push_back(7);
        v.push_back(0);

        for(int i=1; i<n; i++){
            if(!st.empty() && (v[st.top()-'0']==s[i]-'0'))
                st.pop();
            else
                st.push(s[i]);
        }

        return st.size();
    }
};


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}

/* Sample Input2
5
12213
4
1350

Sample Output

*/