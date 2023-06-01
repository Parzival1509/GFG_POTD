// GFG POTD 2022/12/09
// Black and White
// Medium

#include <bits/stdc++.h>
using namespace std;

// O(1) T.C. Solution
long long numOfWays(int n, int m) {
    long long md=1e9+7;
    long long ans=((n*m)%md * (n*m-1)%md)%md;
    if(n>1 and m>2) ans -= 4*(n-1)*(m-2);
    if(n>2 and m>1) ans -= 4*(n-2)*(m-1);
    return ans;
}

// // O(N*M) T.C. Solution
// long long numOfWays(int n, int m) {
//     long long ans=0, md=1e9+7;
//     for(int i=1; i<=n; i++)
//         for(int j=1; j<=m; j++) {
//             int ct=0;
//             if(i-1>0 && j-2>0) ct++;
//             if(i-1>0 && j+2<=m) ct++;
//             if(i-2>0 && j-1>0) ct++;
//             if(i-2>0 && j+1<=m) ct++;
//             if(i+1<=n && j-2>0) ct++;
//             if(i+1<=n && j+2<=m) ct++;
//             if(i+2<=n && j-1>0) ct++;
//             if(i+2<=n && j+1<=m) ct++;
//             ans += (n*m - ct - 1);
//             ans %= md;
//         }
//     return ans;
// }

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}

/* Sample Input
3
2 2
2 3
4 4

Sample Output
12
26
192

*/