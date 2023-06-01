// GFG POTD 2023/05/07
// String Mirror
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringMirror(string str) {
        string temp = "";
        temp += str[0];
        for(int i=1; i<str.length(); i++) {
            if(i != 1 and temp[i-1] == str[i]) temp += str[i];
            else if(temp[i-1] > str[i]) temp += str[i];
            else break;
        }
        string ans = temp;
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        Solution ob;
        string res = ob.stringMirror(str);
        cout<<res<<endl;
    }
}

/* Sample Input:
2
bvdfndkn
casd

Sample Output:
bb
caac

*/