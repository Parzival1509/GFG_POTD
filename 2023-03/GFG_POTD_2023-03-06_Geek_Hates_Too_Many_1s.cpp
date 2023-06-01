// GFG POTD 2023/03/06
// Geek Hates Too Many 1s
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int noConseBits(int n) {
        int ct = 0;
        for(int i=31; i>=0; i--) {
            if((n & (1<<i)) != 0) ct++;
            else ct = 0;

            if(ct == 3) {
                n = n & ~(1<<i);
                ct = 0;
            }
        }
        return n;
    }
};

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }
    return 0;
}

/* Sample Input:
2
2 7

Sample Output:
2
6

*/