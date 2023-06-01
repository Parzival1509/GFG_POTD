// GFG POTD 2023/05/15
// Count Total Setbits
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // ll countBits(ll n) {
    //     ll ans = 0;
        
    //     // // Approach 1: T.C. = O(N), S.C. = O(1)
    //     // for(int i = 1; i<= n; i++)
    //     //     ans += __builtin_popcount(i);
        
    //     // Approach 2: T.C. = O(N), S.C. = O(N)
    //     vector<int> temp(n+1);
    //     temp[0] = 0;
    //     for(int i = 1; i<=n; i++) {
    //         temp[i] = temp[i/2] + i%2;
    //         ans += temp[i];
    //     }
        
    //     return ans;
    // }
    
    // Approach 3: Recursive Method
    int findLargestPower(int n) {
        int x = 0;
        while ((1 << x) <= n)
            x++;
        return x - 1;
    }
    
    ll countBits(int n) {
        if(n <= 1) return n;
        int x = findLargestPower(n);
        return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countBits(n - pow(2, x));
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        Solution ob;
        cout<<ob.countBits(n)<<endl;
    }
}

/* Sample Input:
3
3
4
1000000000

Sample Output:
4
5
14846928141

*/