// GFG POTD 2022/11/24
// Longest Bitonic Subsequence

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int LongestBitonicSequence(vector<int>nums) {
        int n = nums.size();
        
        vector<int> dp1(n, 1);
        for(int i=0; i<n; i++)
            for(int prev=0; prev<i; prev++)
                if(nums[i]>nums[prev] && 1+dp1[prev]>dp1[i]) 
                    dp1[i] = 1+dp1[prev];
                    
        vector<int> dp2(n, 1);
        for(int i=n-1; i>=0; i--)
            for(int prev=n-1; prev>i; prev--)
                if(nums[i]>nums[prev] && 1+dp2[prev]>dp2[i])
                    dp2[i] = 1+dp2[prev];
                    
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
            maxi = max(maxi, dp1[i]+dp2[i]-1);
        return maxi;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans <<"\n";
    }
    return 0;
}


/* Sample Input
2
5
1 2 5 3 2
8
1 11 2 10 4 5 2 1

Sample Output
3
6

*/