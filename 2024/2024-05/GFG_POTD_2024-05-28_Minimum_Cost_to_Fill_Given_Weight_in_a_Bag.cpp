// GFG POTD 2024/05/28
// Minimum Cost to Fill Given Weight in a Bag
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
    
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= w; j++)
                dp[j] = min(dp[j], cost[i] + dp[j - i - 1]); 
    
        return dp[w];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<int> cost(n, 0);
        for(int &i: cost)
            cin >> i;
        cout << ob.minimumCost(n, w, cost) << endl;
    }
    return 0;
}

/* Sample Input
2
5 5
20 10 4 50 100
5 5
-1 -1 4 3 -1

Sample Output
14
-5

*/