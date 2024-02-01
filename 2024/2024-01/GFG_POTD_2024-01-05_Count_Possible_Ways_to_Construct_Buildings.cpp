// GFG POTD 2024/01/05
// Count Possible Ways to Construct Buildings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    
    int TotalWays(int n) {
        if(n == 1) return 4;
        if(n == 2) return 9;
        
        int a = 2, b = 3, s = 0;
        for(int i = 3; i <= n; i++) {
            int c = (a + b) % mod;
            s = (1LL * c * c) % mod; 
            a = b;
            b = c;
        }
        
        return s;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.TotalWays(N);
        cout << ans << "\n";
    }

    return 0;
}

/* Sample Input:
4
1
2
3
4

Sample Output:
4
9
25
64

*/