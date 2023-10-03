// GFG POTD 2023/09/19
// Find First Set Bit
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unsigned int getFirstSetBit(int n) {
        if(n < 2) return n;
        if(n & 1) return 1;
        
        int i = 1, tmp = n;
        while(tmp != 0 && (tmp & 1) == 0) {
            i++;
            tmp >>= 1;
        }
        
        return i;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.getFirstSetBit(n) << endl;
    }

    return 0;
}

/* Sample Input:
3
0
5
18


Sample Output:
0
1
2

*/