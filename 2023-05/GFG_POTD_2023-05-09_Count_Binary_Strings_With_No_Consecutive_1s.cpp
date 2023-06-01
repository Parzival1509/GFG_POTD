// GFG POTD 2023/05/09
// Count Binary Strings With No Consecutive 1s
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long mod = 1e9 + 7; 
    map<long, long> F;
    ll fibo(ll n) {
        if(F.count(n)) return F[n];
        long k = n / 2;
        if(n % 2 == 0) return F[n] = (fibo(k) * fibo(k) + fibo(k - 1) * fibo(k - 1)) % mod;
        return F[n] = (fibo(k) * fibo(k + 1) + fibo(k - 1) * fibo(k)) % mod;
    }
    
    int countStrings(ll n) {
        F[0] = 1;
        F[1] = 1;
        return fibo(n + 1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}

/* Sample Input:
3
2
3
27661428758907

Sample Output:
3
5
382071340

*/