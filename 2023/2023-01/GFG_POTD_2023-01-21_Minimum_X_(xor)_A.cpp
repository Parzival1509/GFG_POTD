// GFG POTD 2023/01/21
// Minimum X (xor) A
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minVal(int a, int b) {
        int x = 0, cnt = __builtin_popcount(b);
        for(int i=31; i>=0; i--)
            if(((1<<i)&a) && cnt>0) {
                cnt--;
                x |= (1<<i);
            }
            else if(i<cnt) {
                x |= (1<<i);
                cnt--;
            }
        return x;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.minVal(a, b);
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
3 5
7 12

Sample Output
3
6

*/