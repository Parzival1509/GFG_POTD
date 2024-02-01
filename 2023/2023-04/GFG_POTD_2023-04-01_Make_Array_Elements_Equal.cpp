// GFG POTD 2023/04/01
// Make Array Elements Equal
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(int n) {
        return ((long long) n*n)/4;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}

/* Sample Input:
4
2 3 4 5

Sample Output:
1
2
4
6

*/