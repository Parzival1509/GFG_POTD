// GFG POTD 2023/02/01
// Distinct Coloring
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {   
public:
    ll distinctColoring(int N, int r[], int g[], int b[]) {
        ll dp[N][3];
        dp[0][0] = r[0];
        dp[0][1] = g[0];
        dp[0][2] = b[0];
        
        for(int i=1; i<N; i++)
            for(int j=0; j<3; j++) {
                if(j == 0)
                    dp[i][j] = r[i] + min(dp[i-1][j+1], dp[i-1][j+2]);
                if(j == 1)
                    dp[i][j] = g[i] + min(dp[i-1][j-1], dp[i-1][j+1]);
                if(j == 2)
                    dp[i][j] = b[i] + min(dp[i-1][j-1], dp[i-1][j-2]);
            }

        return min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2])); 
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin >> N;
        int r[N], g[N], b[N];
        for(int i=0; i<N; i++)
            cin >> r[i];
        for(int i=0; i<N; i++)
            cin >> g[i];
        for(int i=0; i<N; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}

/* Sample Input:
2
3
1 1 1
2 2 2
3 3 3
3
2 1 3
3 2 1
1 3 2

Sample Output:
4
3

*/