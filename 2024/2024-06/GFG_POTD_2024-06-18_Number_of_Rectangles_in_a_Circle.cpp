// GFG POTD 2024/06/18
// Number of Rectangles in a Circle
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectanglesInCircle(int r) {
        int ans = 0;
        for (int i = 1; i < 2 * r; i++)
            for (int j = 1; j < 2 * r; j++)
                if (i * i + j * j <= 4 * r * r)
                    ans++;

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int r;
        cin >> r;
        cout << ob.rectanglesInCircle(r) << endl;
    }
}

/* Sample Input
2
1
2

Sample Output
1
8

*/