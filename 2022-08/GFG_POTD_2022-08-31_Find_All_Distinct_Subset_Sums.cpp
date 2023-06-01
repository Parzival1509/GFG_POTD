// GFG POTD Find all distinct subset (or subsequence) sums
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dp[10001][101] ;
    void sol(std::vector<int>& v , int n , int sum)
    {
        if(n == 0)
        {
            dp[sum][n] = true ;
            return ;
        }
        if(dp[sum][n])
            return ;
        
        if(sum - v[n-1] >= 0)
        {
            sol(v,n-1,sum-v[n-1]) ;
            sol(v,n-1,sum) ;
        }
        else
            sol(v,n-1,sum) ;    
        dp[sum][n] = true ; 
    }

    vector<int> DistinctSum(vector<int>nums){
        memset(dp,false , sizeof dp) ;
        int sum = 0 ;
        for(auto el:nums)
            sum += el ;
        sol(nums,nums.size(),sum) ;
        std::vector<int> ans;
        for(int i=0;i<=sum;++i)
        {
            for(int j=0;j<=100;++j)
            if(dp[i][j])
            {
                ans.push_back(i) ;
                break;
            }
        }
        return ans ;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        Solution obj;
        vector<int> ans = obj.DistinctSum(nums);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
    }
    return 0;
}