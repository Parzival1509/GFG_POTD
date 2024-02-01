// GFG POTD 2023/02/20
// Count Cyclic Paths
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n) {
        long long int ans = 0;
        for(int i = 1; i < n; i++) {
            ans = ((ans % mod) * 3) % mod;
            if(i%2 == 1) ans = (ans + 3) % mod;
            else ans -= 3;
        }
        return ans % mod;
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

/* Sample Input:
2
1
2

Sample Output:
0
3

*/