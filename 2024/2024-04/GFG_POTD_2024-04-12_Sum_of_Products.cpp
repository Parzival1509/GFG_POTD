// GFG POTD 2024/04/12
// Sum of Products
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll pairAndSum(int n, ll arr[]) {
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            ll k = 0;
            for (int j = 0; j < n; j++) {
                if ((arr[j] & (1 << i)) != 0)
                    k++;
            }
            ans += (1 << i) * ((k) * (k - 1)) >> 1;
        }

        return ans;
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.pairAndSum(n, arr) << endl;
    }
}

/* Sample Input
2
3
5 10 15
4
10 20 30 40

Sample Output
15
46

*/