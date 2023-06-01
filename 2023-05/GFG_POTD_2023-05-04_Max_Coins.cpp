// GFG POTD 2023/05/04
// Max Coins
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1
    int solve(vector<vector<int>> &v, int i, int rem, vector<vector<int>> &dp) {
        // rem = number of intervals need to be choosen (remaining)
        if(rem == 0 || i == v.size()) return 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        
        int notTake = solve(v, i+1, rem, dp), take = v[i][2];
        int low = i+1, high = v.size()-1, idx = v.size();
        while(low <= high) {
            int mid = (low+high)/2;
            if(v[mid][0] >= v[i][1]) {
                idx = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        take += solve(v, idx, rem-1, dp);
        return dp[i][rem] = max(take, notTake);
    }
    
    int maxCoins(int n,vector<vector<int>> &ranges) {
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> dp(ranges.size(), vector<int> (3, -1));
        return solve(ranges, 0, 2, dp);
    }

    // // Approach 2
    // static bool comp(vector<int> &a, vector<int> &b) {
    //     return a[2] > b[2];
    // }
    
    // int maxCoins(int n,vector<vector<int>> &ranges) {
    //     sort(ranges.begin(), ranges.end(), comp);
    //     int ans = ranges[0][2];
    //     for(int i = 0; i < n - 1; i++) {
    //         int s = ranges[i][0], e = ranges[i][1], c = ranges[i][2];
    //         int maxi = 0, j = i + 1;
    //         while(j < n) {
    //             if(ranges[j][2] + c < ans) break;
    //             if(ranges[j][0] >= e or s >= ranges[j][1]) 
    //                 maxi = max(maxi, ranges[j][2]);
    //             j++;
    //         }
    //         ans = max(ans, c + maxi);
    //     }
    //     return ans;
    // }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> a(n, vector<int> (3));
        for(int i=0; i<n; i++)
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        Solution ob;
        cout<<ob.maxCoins(n, a)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
1 3 4
2 3 5
3 4 2
5
1 3 4
2 3 5
3 4 2
5 8 9
2 8 10

Sample Output:
7
14

*/