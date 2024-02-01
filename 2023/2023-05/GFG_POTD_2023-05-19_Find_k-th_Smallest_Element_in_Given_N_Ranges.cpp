// GFG POTD 2023/05/19
// Find k-th Smallest Element in Given N Ranges
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto it: intervals)
            if(!ans.empty() && it[0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], it[1]);
            else ans.push_back(it);

        return ans;
    }
    
    vector<int> kthSmallestNum(int n, vector<vector<int>>& range, int q, vector<int> queries) {
        vector<vector<int>> v = merge(range);
        int sz = v.size();
        vector<int> presum(sz, 0);
        presum[0] = v[0][1] - v[0][0] + 1; 
        for(int i=1; i<sz; i++)
            presum[i] = presum[i-1] + v[i][1] - v[i][0] + 1;
            
        vector<int> ans(q, -1);
        for(int i=0; i<q; i++) {
            int idx = lower_bound(presum.begin(), presum.end(), queries[i]) - presum.begin();
            if(idx >= sz || presum[idx] < queries[i])
                continue; 
            int left = queries[i] - (idx-1 >= 0? presum[idx-1]: 0);
            if(idx >= 0 && v[idx][0]+left-1 <= v[idx][1])
                ans[i] = v[idx][0] + left - 1;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>>range(n, vector<int>(2, 0));
        for(int i = 0 ; i < n; i++)
            cin >> range[i][0] >> range[i][1];
        int q;
        cin >> q;
        vector<int>queries;
        for(int i = 0 ; i < q; i++) {
            int x;
            cin >> x;
            queries.push_back(x);
        }
        Solution ob;
        vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
        for(auto it: ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2

2
1 4
6 8
3
2 4 10

2
2 6
5 7
2
5 8

Sample Output:
2 4 -1 
6 -1 

*/