// GFG POTD 2023/07/01
// Number of 1 Bits
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setBits(int N) {
        return __builtin_popcount(N);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

/* Sample Input:
3
6 8 11

Sample Output:
2
1
3

*/