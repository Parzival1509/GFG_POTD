// GFG POTD 2023/08/08
// Fraction Pairs With Sum 1
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countFractions(int n, int numerator[], int denominator[]) {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int t = __gcd(numerator[i], denominator[i]);
            int a = numerator[i] / t, b = denominator[i] / t;
            mp[{a, b}]++;
        }
        
        for(auto &it: mp) {
            int u = it.first.first, v = it.first.second;
          
            if(u != v) {
            int a = v - u;
                if(a == u)
                    ans += ((mp[{a, v}] - 1) * mp[{a, v}]);
                else ans += (mp[{a, v}] * mp[{u, v}]);
            }
        }
        
        return ans / 2;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int numerator[n], denominator[n];
        for(int i = 0; i < n; i++)
            cin >> numerator[i];
        for(int i = 0; i < n; i++)
            cin >> denominator[i];
        Solution ob;
        int ans = ob.countFractions(n, numerator, denominator);
        cout << ans << endl;
    }
}

/* Sample Input:
2
4
1 2 2 8
2 4 6 12
5
3 1 12 81 2
9 10 18 90 5

Sample Output:
2
2

*/