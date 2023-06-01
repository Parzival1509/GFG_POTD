// GFG POTD Filling Bucket

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 100000000;
    int dp[100010];
    int sol(int n){
        if(n<0)
            return 0 ;
        if(n == 0)
            return 1;  
        if(dp[n] != -1) return dp[n];
        return dp[n] = (sol(n-1)+sol(n-2))%M;
    }
    int fillingBucket(int N){
        memset(dp,-1,sizeof dp);
        return sol(N);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}

/* Sample Input
3
2
3
4
8223

Sample Output
2
3
5
27851643

*/