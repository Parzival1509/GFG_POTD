// GFG POTD 2023/09/21
// Stickler Thief
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int FindMaxSum(int arr[], int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = arr[0];
        
        for(int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
        
        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        cout << ob.FindMaxSum(a, n) << endl;
    }

    return 0;
}

/* Sample Input:
2
5
6 5 5 7 4
3 
1 5 3

Sample Output:
15
5

*/