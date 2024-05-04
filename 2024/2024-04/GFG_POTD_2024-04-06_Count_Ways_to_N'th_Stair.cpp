// GFG POTD 2024/04/06
// Count Ways to N'th Stair
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countWays(int n) {
        return (n / 2) + 1;
    }
};

int main() {
    int tc;
    cin >> tc;
    Solution ob;
    while (tc--) {
        int n;
        cin >> n;
        cout << ob.countWays(n) << endl;
    }
    return 0;
}

/* Sample Input
2
4
5

Sample Output
3
3

*/