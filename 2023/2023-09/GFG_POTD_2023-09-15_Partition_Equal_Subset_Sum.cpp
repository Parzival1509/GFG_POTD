// GFG POTD 2023/09/15
// Partition Equal Subset Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPartition(int n, int arr[]) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        
        // Odd Sum
        if(sum & 1) return 0;
        
        // Even Sum
        sum >>= 1;
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= sum; j++) {
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
            
        return dp[n][sum];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N;i++)
            cin >> arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/* Sample Input:
4
4
1 5 11 5
3
1 3 5
3
1 2 3
8
478 757 314 471 729 100 459 618

Sample Output:
YES
NO
YES
NO

*/