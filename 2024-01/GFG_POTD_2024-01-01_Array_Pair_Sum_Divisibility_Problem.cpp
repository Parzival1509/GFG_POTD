// GFG POTD 2024/01/01
// Array Pair Sum Divisibility Problem
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n & 1) return false;
        
        vector<int> rem(k, 0);
        for(int i: nums)
            rem[i % k]++;
            
        int ct = 0;
        for(int i = 0; i <= k / 2; i++) {
            if(i == 0 || 2 * i == k)
                ct += rem[i] / 2;
            else ct += min(rem[i], rem[k - i]);
        }
        
        return ct == n / 2;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if(ans) cout << "True\n";
        else cout << "False\n";
    }
    
    return 0;
}

/* Sample Input:
2
4 6
9 7 5 3
3 4
4 4 4

Sample Output:
True
False

*/