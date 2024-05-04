// GFG POTD 2024/04/05
// Strictly Increasing Array
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int min_operations(vector<int>& nums) {
        int n = nums.size(), LIS = 1;
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] && (nums[i] - nums[j]) >= (i - j)) {
                    dp[i] = max(1 + dp[j], dp[i]);
                    LIS = max(LIS, dp[i]);
                }
        
        return (n - LIS);
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
6
1 2 3 6 5 4
4
1 1 1 1

Sample Output
2
3

*/