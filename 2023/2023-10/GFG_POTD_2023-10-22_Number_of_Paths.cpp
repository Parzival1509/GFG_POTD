// GFG POTD 2023/10/22
// Number of Paths
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;
    
    ll power(ll x, int y, int p) {
        ll res = 1;
        while(y > 0) {
            if(y & 1)
                res = (res * x) % p;
            y >>= 1;
            x = (x * x) % p;
        }
        
        return res;
    }
    
    ll modInverse(ll n, int p) {
        return power(n, p - 2, p);
    }
    
    ll numberOfPaths(int M, int N) {
        ll path = 1, mod = 1e9 + 7;
        
        for(ll i = N; i < (M + N - 1); i++) {
            path = (path * i) % mod;
            ll inv = modInverse(i - N + 1, mod);
            path = (path * inv) % mod;
        }
        
        return path;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> M >> N;
        Solution ob;
        cout << ob.numberOfPaths(M, N) << endl;
    }

    return 0;
}

/* Sample Input:
4
1 4
3 3
5 19
10 100000000

Sample Output:
1
6
7315
799292476

*/