// GFG POTD 2023/02/17
// Is it Fibonacci
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll solve(int n, int k, vector<ll> gnum) {
        int i = 0, j = k-1;
        ll sum = accumulate(gnum.begin(), gnum.end(), 0);
        while(j < n) {
            gnum.push_back(sum);
            sum = sum - gnum[i++] + gnum[++j];
        }
        return gnum[n-1];
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> GeekNum(K);
        for(int i = 0; i < K; i++)
            cin >> GeekNum[i];
        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

/* Sample Input:
2
6 1
4
5 3
0 1 2

Sample Output:
3
2

*/