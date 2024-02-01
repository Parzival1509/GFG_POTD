// GFG POTD 2023/01/31
// Minimum times A has to be repeated such that B is a substring of it
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRepeats(string a, string b) {
        string tmp = a;
        int ct = 1;

        while(a.size() < b.size()) {
            a += tmp;
            ct++;
        }
        if(a.find(b) != -1) return ct;

        a += tmp;
        if(a.find(b) != -1) return ct+1;
        return -1;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string a, b;
        cin>>a>>b;
        Solution ob;
        cout << ob.minRepeats(a, b) << endl;
    }
    return 0;
}

/* Sample Input:
3
abcd
cdabcdab
ab
cab
wwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

Sample Output:
3
-1
4

*/