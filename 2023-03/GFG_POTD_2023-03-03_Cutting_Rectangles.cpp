// GFG POTD 2023/03/03
// Cutting Rectangles
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<ll> minimumSquares(ll len, ll b) {
        ll k = __gcd(len, b);
        ll n = (len*b) / (k*k);
        return {n, k};
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        ll len, b;
        cin>>len>>b;
        
        Solution ob;
        vector<ll> ans = ob.minimumSquares(len, b);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}

/* Sample Input:
2
2 4
6 3

Sample Output:
2 2
2 3

*/