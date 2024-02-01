// GFG POTD 2022/12/11
// Array Pair Sum Divisibility Problem
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        vector<int> rem(k,0);
        for(auto it: nums)
            rem[it%k]++;
        for(int i=1; i<k; i++)
            if(rem[i] != rem[k-i])
                return false;
        return !(rem[0] & 1);
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
        if(ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}

/* Sample Input
2
4 6
9 5 7 3
4 4
2 4 1 3

Sample Output
True
False

*/