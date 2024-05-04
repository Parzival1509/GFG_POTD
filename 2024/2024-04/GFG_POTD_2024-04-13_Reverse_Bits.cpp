// GFG POTD 2024/04/13
// Reverse Bits
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long reversedBits(long long x) {
        long long ans = 0;
        int cnt = 31;
        while (cnt) {
            if (x && (x & 1))
                ans |= 1;
            ans <<= 1;
            x >>= 1;
            cnt--;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        cin >> X;
        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}

/* Sample Input
2
1
5

Sample Output
2147483648
2684354560

*/