// GFG POTD 2024/06/13
// Padovan Sequence
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int padovanSequence(int n) {
        int prev2 = 1, prev1 = 1, prev = 1, mod = 1e9 + 7;
        if (n == 0 || n == 1 || n == 2)
            return prev;

        for (int i = 1; i <= n - 2; i++) {
            int curr = (prev2 + prev1) % mod;
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}

/* Sample Input
2
3
4

Sample Output
2
2

*/