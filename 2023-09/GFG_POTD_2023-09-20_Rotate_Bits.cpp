// GFG POTD 2023/09/20
// Rotate Bits
// Basic (Medium)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotate(int n, int d) {
        d %= 16;
        vector<int> bits(16, 0);
        for(int i = 0; i < 16; i++) {
            bits[i] = n & 1;
            n >>= 1;
        }
        
        int left = 0, right = 0;
        int i = (16 - d) % 16, j = d, k = 0;
        
        while(k < 16) {
            if(bits[i])
                left += 1 << k;
            if(bits[j])
                right += 1 << k;
                
            i = (i + 1) % 16;
            j = (j + 1) % 16;
            k++;
        }
        
        return {left, right};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        Solution ob;
        vector<int> res = ob.rotate (n, d);
        cout << res[0] << ' ' << res[1] << endl;
    }
}

/* Sample Input:
3
28 2
29 2
8426 12464

Sample Output:
112 7
116 16391
8426 8426

*/