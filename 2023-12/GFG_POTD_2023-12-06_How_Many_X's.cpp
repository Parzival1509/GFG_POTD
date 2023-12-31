// GFG POTD 2023/12/06
// How Many X's?
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countX(int L, int R, int X) {
        int ans = 0;
        for(int i = L + 1; i < R; i++) {
            int n = i;
            while(n > 0) {
                if(n % 10 == X) ans++;
                n /= 10;
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

/* Sample Input:
2
10 19 1
18 81 9

Sample Output:
9
7

*/