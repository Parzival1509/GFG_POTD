// GFG POTD 2023/08/27
// Reverse a String
// Basic

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWord(string str) {
        for(int i = 0; i < str.size() / 2; i++)
            swap(str[i], str[str.size() - 1 - i]);
        return str;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseWord(s) << endl;
    }
    return 0;
}

/* Sample Input:
2
Geeks
for

Sample Output:
skeeG
rof

*/