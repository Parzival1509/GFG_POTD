// GFG POTD 2023/01/04
// Maximum Profit by Choosing a Subset of Intervals
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Approach 1
	static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1] == b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> ans(n);
        ans[0]=intervals[0][2];
        for(int i=1; i<n; i++) {
            ans[i] = intervals[i][2];
            for(int j=0; j<i; j++)
                if(intervals[j][1] <= intervals[i][0])
                    ans[i] = max(ans[i], ans[j]+intervals[i][2]);
        }
        return *max_element(ans.begin(), ans.end());
    }

    // // Approach 2
    // int maximum_profit(int n, vector<vector<int>> &intervals) {
    //    	sort(intervals.begin(), intervals.end());
    //     vector<int> dp(n, -1);
    //     function<int(int, int)> dfs = [&](int idx, int end) {
    //         if(idx == n) return 0;
    //         if(intervals[idx][0] < end) return dfs(idx+1, end);
    //         if(dp[idx] != -1) return dp[idx];
    //         return dp[idx] = max(intervals[idx][2] + dfs(idx+1, intervals[idx][1]), dfs(idx+1, end));
    //     };
    //     return dfs(0, 0);
    // }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for(int i=0; i<n; i++)
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

/* Sample Input
2
3
1 2 4
1 5 7
2 4 4
3
1 4 4
2 3 7
2 3 4

Sample Output
8
7

*/