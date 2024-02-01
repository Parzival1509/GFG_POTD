// GFG POTD 2023/01/29
// Min Operations
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int a, int b) {
        if(a == b) return 0;
        int c = a&b;
        if(c==a || c==b) return 1;
        return 2;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a, b;
        cin>>a>>b;
        Solution obj;
        int res = obj.solve(a, b);
        cout<<res<<endl;
    }
}

/* Sample Input
2
5 12
2 2

Sample Output
2
0

*/