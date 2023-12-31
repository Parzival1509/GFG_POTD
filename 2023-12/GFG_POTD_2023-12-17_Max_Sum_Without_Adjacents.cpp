// GFG POTD 2023/12/17
// Max Sum Without Adjacents
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxSum(int *arr, int n) {
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);
        
        // // Approach 1: Tabulation, S.C. = O(N)
        // vector<int> dp(n, 0);
        // dp[0] = arr[0];
        // dp[1] = max(dp[0], arr[1]);
         
        // for(int i = 2; i < n; i++)
        //     dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
         
        // return dp[n - 1];
        
        // Approach 2: Space Optimised DP, S.C. = O(1)
        int prev = arr[0], curr = max(prev, arr[1]);
        for(int i = 2; i < n; i++) {
            int sum = max(curr, prev + arr[i]);
            prev = curr;
            curr = sum;
        }
        
        return curr;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }

    return 0;
}

/* Sample Input:
3
1
1
4
3 2 7 10
6
5 5 10 100 10 5

Sample Output:
1
13
110

*/