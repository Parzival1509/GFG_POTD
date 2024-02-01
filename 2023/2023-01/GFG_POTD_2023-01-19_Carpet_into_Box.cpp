// GFG POTD 2023/01/19
// Carpet into Box
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int a, int b, int c, int d) {
        if((a<=c && b<=d) || (a<=d && b<=c))
            return 0;
        if(a > c) a /= 2;
        else b /= 2;
        return 1+solve(max(a, b), min(a, b), c, d);
    }

    int carpetBox(int a, int b, int c, int d) {
        return solve(max(a, b), min(a, b), max(c, d), min(c, d));
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        Solution ob;
        int ans = ob.carpetBox(a, b, c, d);
        cout<<ans<<endl;
    }
}

/* Sample Input
2
8 13 6 10
4 8 3 10

Sample Output
1
1

*/