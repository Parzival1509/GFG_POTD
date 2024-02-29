// GFG POTD 2024/02/29
// 
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll sumBitDifferences(int arr[], int n) {
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            ll count = 0;
            for (int j = 0; j < n; j++)
                if (arr[j] & (1 << i))
                    count++;
            ans += count * (n - count) * 2;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
2
1 2
3
1 3 5

Sample Output
4
8

*/