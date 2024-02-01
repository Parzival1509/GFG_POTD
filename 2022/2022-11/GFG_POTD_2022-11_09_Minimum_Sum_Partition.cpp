// GFG POTD 2022/11/09
// Minimum Sum Partition

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minDifference(int arr[], int n) { 
        long long sum=0;
        for(int i=0; i<n; i++)
            sum += arr[i];
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=sum; j++)
                if(j==0)
                    dp[i][j] = true;
                else if(i==0)
                    dp[i][j] = false;
                else if(arr[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];

        // Find the min difference value
        int diff=INT_MAX;
        for(int i=0; i<=sum; i++){
            int first = i;
            int second = sum-i;
            if(dp[n][i]==true and diff>abs(first-second))
                diff = abs(first-second);
        }
        return diff;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}

/* Sample Input
2
8
4 2 4 5 2 3 3 1
8
1 7 5 7 5 4 7 4

Sample Output
1
3

*/