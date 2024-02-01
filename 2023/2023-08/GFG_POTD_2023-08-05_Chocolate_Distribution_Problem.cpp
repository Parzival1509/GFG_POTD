// GFG POTD 2023/08/05
// Chocolate Distribution Problem
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        sort(a.begin(), a.end());
        long long ans = a[n - 1] - a[0];
        
        for(int i = 0; i <= n - m; i++)
            ans = min(ans, a[i + m - 1] - a[i]);
        return ans;
    }   
};

int main() {
    long long t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n, 0);
        for(auto &i: a)
            cin >> i;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
}

/* Sample Input:
2
8 5
3 4 1 9 56 9 12
7 3
7 3 2 4 9 12 56

Sample Output:
6
2

*/