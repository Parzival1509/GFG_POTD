// GFG POTD 2023/07/12
// Power Of Numbers
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll mod = 1e9 + 7;
        
    ll power(int N, int R) {
        if(R == 1) return N;
        
        if(R % 2 == 0)
            return power((1ll * N * N) % mod, R / 2);
        return (1ll * N * power((1ll * N * N) % mod, R / 2) % mod);
    }

};

long long rev(long long n) {
    long long rev_num = 0;
    while(n > 0) { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
    } 
    return rev_num;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long N, R = 0;
        cin>>N;
        R = rev(N);
        Solution ob;
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}

/* Sample Input:
2
2 12

Sample Output:
4
864354781

*/