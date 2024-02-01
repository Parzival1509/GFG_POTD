// GFG POTD 2024/01/02
// Largest Sum Subarray of Size at least K
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxSumWithK(ll a[], ll n, ll k) {
        int maxSum[n];
        maxSum[0] = a[0];
        
        int curr_max = a[0];
        for(int i = 1; i < n; i++) {
            curr_max = max(a[i], curr_max+a[i]);
            maxSum[i] = curr_max;
        }
        
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += a[i];
        
        int result = sum;
        for(int i = k; i < n; i++) {
            sum = sum + a[i] - a[i-k];
            result = max(result, sum);
            result = max(result, sum + maxSum[i - k]);
        }
        
        return result;
    }
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, i;
        cin >> n  >> k;
        ll a[n];
        for(i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

/* Sample Input:
2
4 2
1 -2 2 -3
6 2
1 1 1 1 1 1

Sample Output:
1
6

*/