// GFG POTD 2023/10/23
// Maximum Sum Increasing Subsequence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumIS(int arr[], int n) {
        int dp[n];
        
        for(int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for(int j = 0; j < i; j++)
                if(arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
        }
        
        return *max_element(dp, dp + n);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }

    return 0;
}

/* Sample Input:
2
5
1 101 2 3 100
4
4 1 2 3

Sample Output:
106
6

*/