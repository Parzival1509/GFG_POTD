// GFG POTD 2022/11/04
// Base Equivalence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string baseEquiv(int n, int m){
        for(int i=2; i<=32; i++)
            if(n>pow(i, m-1) && n<pow(i, m))
                return "Yes";
        return "No";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

/* Sample Input
2
8 2
8 3

Sample Output
Yes
No

*/