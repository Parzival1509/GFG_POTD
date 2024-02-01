// GFG POTD 2023/01/25
// Type it!
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperation(string s) {
        int n = s.size();
        if(n < 4) return n;
        int j = n-1;
        while(j > 0) {
            if(j%2 == 0) j--;
            int mid = j/2;
            if(s.substr(0, mid+1) == s.substr(mid+1, mid+1))
                return n-mid;
            j--;
        }
        return n;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

/* Sample Input
2
abcabca
abcdefgh

Sample Output
5
8

*/