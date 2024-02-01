// GFG POTD 2023/06/12
// Rod Cutting
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(int price[], int n) {
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            dp[i] = price[i - 1];
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i/2; j++)
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        
        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        Solution ob;
        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}

/* Sample Input:
2
8
1 5 8 9 10 17 17 20
8
3 5 8 9 10 17 17 20

Sample Output:
22
24 

*/