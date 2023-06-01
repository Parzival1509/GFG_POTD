// GFG POTD 2023/04/09
// Special Digits
// Hard

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

class Solution {
public:
    bool check(int n , int c , int d) {
        while(n) {
            int r = n % 10;
            n /= 10;
            if(r != c && r != d)
            return false;
        }
        return true;
    }
    
    ll binpower(ll a , ll n) {
        ll res = 1;
        while(n) {
            if(n % 2)
            res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }
    
    int bestNumbers(int n, int a, int b, int c, int d) {
        ll res = 0, fact[n + 1];
        fact[0] = 1;
        for(int i = 1 ; i <= n ; i++)
            fact[i] = (fact[i - 1] * 1LL * i) % mod;
        for(int i = 0 ; i <= n ; i++) {
            int cnta = i , cntb = n - i;
            if(check(cnta * a + cntb * b , c , d)) {
                res += (fact[n] * binpower((fact[i] * fact[n - i]) % mod , mod - 2)) % mod;
                res %= mod;
            }
        }
        return res;
    }
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        int n, a, b, c, d;
        cin>>n>>a>>b>>c>>d;
        Solution obj;
        int res = obj.bestNumbers(n, a, b, c, d);
        cout<<res<<endl;
    }
}

/* Sample Input:
2
2 1 2 3 5
1 1 1 2 3

Sample Output:
2
0

*/