// GFG POTD 2022/09/30
// Find the Safe Position
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int n, int k) {
        if(n==1) return 0;
        int x=func(n-1, k);
        int y=(x+k)%n;
        return y;
    }
    int safePos(int n, int k) {
        return 1+func(n, k);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}

/* Sample Input
2
2 1
4 2

Sample Output
2
1

*/