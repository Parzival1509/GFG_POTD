// GFG POTD 2024/06/24
// Summed Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumMatrix(long long n, long long q) {
        if (n * 2 < q)
            return 0;
        return n - abs(n + 1 - q);
    }
};

int main() {
    int T;
    cin >> T;
    Solution ob;
    while(T--) {
        long long n, q;
        cin >> n >> q;
        cout << ob.sumMatrix(n, q) << endl;
    }

    return 0;
}

/* Sample Input
2
4 7
5 4

Sample Output
2
3

*/