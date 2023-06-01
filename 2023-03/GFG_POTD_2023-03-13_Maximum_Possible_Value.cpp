// GFG POTD 2023/03/13
// Maximum Possible Value
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxPossibleValue(int n, vector<int> a, vector<int> b) {
        ll ans = 0;
        int sticks = 0, mn = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(b[i] % 2) b[i]--;
            if(b[i] > 0) {
                sticks += b[i];
                ans += a[i] * b[i];
                mn = min(a[i], mn);
            }
        }
        if(sticks % 4 != 0) ans -= 2*mn;
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
          cin>>B[i];
        Solution obj;
        auto ans = obj.maxPossibleValue(N, A, B);
        cout<<ans<<endl;
    }
}

/* Sample Input:
2
4
3 4 5 6
2 3 1 6
1
3
2

Sample Output:
38
0

*/