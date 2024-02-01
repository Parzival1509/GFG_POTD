// GFG POTD 2023/01/27
// Total Decoding Messages
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod (int)(1e9+7)

class Solution {
public:
    int f(int ind, string& str, int n, vector<ll>& dp) {
         if(ind == n) return 1;
         if(dp[ind] != -1) return dp[ind];

         int onech = 0, twoch = 0;
         if(str[ind]>='1' && str[ind]<='9')
             onech = f(ind+1, str, n, dp);
         string temp = str.substr(ind, 2);
         if(ind<n-1 && temp>="10" && temp<="26")
             twoch = f(ind+2, str, n, dp);
         return dp[ind] = (onech+twoch)%mod;
    }
    int CountWays(string str){
        int n = str.length();
        vector<ll> dp(n, -1);
        return f(0, str, n, dp);
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
123
90

Sample Output
3
0

*/