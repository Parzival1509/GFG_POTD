// GFG POTD 2024/02/12
// Recursive Sequence
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    
    long long sequence(int n) {
        long long ans = 0, cnt = 1;
        
        for(int i = 1; i <= n; i++) {
            int val = i, tmp = 1;
            while(val--) {
                tmp = (tmp * cnt) % mod;
                cnt++;
            }
            ans = (ans + tmp) % mod;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;        
        Solution ob;
        cout << ob.sequence(N) << endl;
    }
    return 0;
}

/* Sample Input:
2
5
7

Sample Output:
365527
6997165

*/