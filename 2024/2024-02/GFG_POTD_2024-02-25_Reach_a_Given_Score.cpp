// GFG POTD 2024/02/25
// Reach a Given Score
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll count(ll n) {
        int ans = 0;
        for (int i = 0; i <= n / 3; i++) {
            int x = n - i * 3;
            if (x % 5 == 0)
                ans += (1 + x / 10);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        Solution obj;
        cout << obj.count(n) << endl;
    }

    return 0;
}

/* Sample Input
2
10
20

Sample Output
2
4

*/