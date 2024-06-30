// GFG POTD 2024/06/03
// Trail of Ones
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfConsecutiveOnes(int n) {
        if (n == 2)
            return 1;

        int a = 0, b = 1, ans = 1, mod = 1e9 + 7;
        for (int i = 3; i <= n; i++) {
            int c = (a + b) % mod;
            a = b;
            b = c;
            ans = ((ans * 2) % mod + c) % mod;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

/* Sample Input
3
2
3
5

Sample Output
1
3
19

*/