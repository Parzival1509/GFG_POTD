// GFG POTD 2024/05/12
// Minimum Steps to Destination
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int d) {
        // // Approach 1:
        // int pos = 0, step = 0;
        // while (pos < d || ((pos - d) % 2 != 0)) {
        //     step++;
        //     pos += step;
        // }

        // return step;

        // Approach 2: T.C. = O(sqrt(d))
        int x = ceil((-1 + sqrt(1 + 8 * d)) / 2);

        if ((x * (x + 1) / 2 - d) % 2 == 0)
            return x;
        if (x % 2 == 0)
            return x + 1;
        return x + 2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}

/* Sample Input
2
2
10

Sample Output
3
4

*/