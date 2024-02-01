//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int dp[1050][1050];

 int solve(int h, int  m , int r)
 {
 	if(h <= 0 || m <=0)
 		return 0;
 	if(dp[h][m] != -1)
 		return dp[h][m];
 	int ans;
 	if(r!=1)
 		ans = 1+solve(h+3, m+2, 1);
 	else
 	{
 		int a = solve(h-5, m-10, 2);
 		int b = solve(h-20, m+5, 3);
 		ans = max( a,b );
 		if(ans)ans += 1;
 	}
 	return dp[h][m] = ans;
 }

 int maxLevel(int h, int m)
        {
            // code here
            memset(dp, -1, sizeof(dp));
            return solve(h, m, 0);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends