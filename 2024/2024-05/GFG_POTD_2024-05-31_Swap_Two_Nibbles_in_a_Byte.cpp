// GFG POTD 2024/05/31
// Swap Two Nibbles in a Byte
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swapNibbles(int n) {
        int right = (n >> 4);
        int left = (n << 4) & 255;

        return right + left;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}

/* Sample Input
2
100
129

Sample Output
70
24

*/