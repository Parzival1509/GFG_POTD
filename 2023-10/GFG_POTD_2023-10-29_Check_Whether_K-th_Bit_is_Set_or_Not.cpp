// GFG POTD 2023/10/29
// Check Whether K-th Bit is Set or Not
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkKthBit(int n, int k) {
        return n & (1 << k);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        int k;
        cin >> k;
        Solution obj;
        if(obj.checkKthBit(n, k))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

/* Sample Input:
3
4 0
4 2
500 3

Sample Output:
No
Yes
No

*/