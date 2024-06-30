// GFG POTD 2024/06/20
// Integral Points Inside Triangle
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long InternalCount(long long p[], long long q[], long long r[]) {
        long long area = 0, pb = 0;

        area += (p[0] * q[1]) - (p[1] * q[0]);
        area += (q[0] * r[1]) - (q[1] * r[0]);
        area += (r[0] * p[1]) - (r[1] * p[0]);

        pb += __gcd(abs(p[0] - q[0]), abs(p[1] - q[1]));
        pb += __gcd(abs(r[0] - q[0]), abs(r[1] - q[1]));
        pb += __gcd(abs(p[0] - r[0]), abs(p[1] - r[1]));

        return abs(area) / 2 - pb / 2 + 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long ans = ob.InternalCount(p, q, r);
        cout << ans << endl;
    }
}

/* Sample Input
2
0 0 0 5 5 0
62 -3 5 -45 -19 -23

Sample Output
6
1129

*/