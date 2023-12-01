// GFG POTD 2023/11/05
// Top K Frequent Elements in Array I
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
            
        priority_queue<pair<int, int>> pq;
        for(auto it: mp)
            pq.push({it.second, it.first});
            
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(auto &i : nums)
            cin >> i;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for(auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input:
2
6 2
1 1 1 2 2 3
8 2
1 1 2 2 3 3 3 4

Sample Output:
1 2 
3 2 

*/