// GFG POTD Count All Possible Paths From Top Left to Bottom Right

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101];
    
    bool possible(int x, int y, int m, int n ){
        return x<m and x>=0 and y<n and y>=0;
    }

    long long fun(int x, int y, int m, int n){
        if(x == 0 and y == 0)
            return 1;
        if(!possible(x,y,m,n))
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        return dp[x][y] = (fun(x-1,y,m,n) + fun(x,y-1,m,n))%1000000007 ;
    }
  
    long long int numberOfPaths(int m, int n){
        memset(dp,-1,sizeof dp) ;
        return fun(m-1 , n-1, m ,n) ;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

/* Sample Input
2
2 2
3 3

Sample Output
2
6

*/