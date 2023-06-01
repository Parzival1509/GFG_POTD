#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> dp = decltype(dp)(202, vector<int>(202, -1));    
    int eggDrop(int egg, int flr)
    {
        if(egg==0)
            return INT_MAX;
        if(egg==1)
            return flr;
        if(flr==1)
            return 1;
        if(flr==0)
            return 0;
        if(dp[egg][flr] != -1)
            return dp[egg][flr];
        
        int mini = INT_MAX;
        for(int f = 1; f <=flr; f++)
            mini = min(mini, max(eggDrop(egg-1, f-1), eggDrop(egg, flr-f)));

        return dp[egg][flr] = mini+1; 
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}