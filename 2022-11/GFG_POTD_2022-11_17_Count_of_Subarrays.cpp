// GFG POTD 2022/11/17
// Count of Subarrays

#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution{
public:
    ll countSubarray(int arr[], int n, int k) {
        ll ans=(ll)n*(n+1)/2;
        ll l=0;
        for(int i=0; i<n; i++) {
            if(arr[i]<=k)
                l++;
            else {
                ans -= l*(l+1)/2;
                l=0;
            }
        }
        ans -= l*(l+1)/2;
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
3 2
3 2 1
4 1
1 2 3 4

Sample Output
3
9

*/