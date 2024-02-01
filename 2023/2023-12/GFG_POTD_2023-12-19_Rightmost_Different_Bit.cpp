// GFG POTD 2023/12/19
// Rightmost Different Bit
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int posOfRightMostDiffBit(int m, int n) {
        if(m == n) return -1;
        
        for(int i = 1; i <= 32; i++) {
            int x = m & 1;
            m = m >> 1;
            int y = n & 1;
            n = n >> 1;
            
            if(x ^ y == 1) return i;
        }
        
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
         int m, n;
         cin >> m >> n;
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n) << endl;
    }

    return 0;     
}

/* Sample Input:
2
11 9
15 3

Sample Output:
2
3

*/