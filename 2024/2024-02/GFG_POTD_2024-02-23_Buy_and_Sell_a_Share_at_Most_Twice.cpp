// GFG POTD 2024/02/23
// Buy and Sell a Share at Most Twice
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<int> mx(n, 0);
        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            int last = mx[k];
            mx[k] = (k ? mx[k - 1] : 0) + (k & 1 ? price[k] : -price[k]);
            for (int i = k + 1; i < n; ++i) {
                int tmp = last + (k & 1 ? price[i] : -price[i]);
                last = mx[i];
                mx[i] = max(tmp, mx[i - 1]);
            }
            ans = max(mx[n - 1], ans);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        Solution obj;
        cout << obj.maxProfit(price) << endl;
    }
}

/* Sample Input
2
6
10 22 5 75 65 80
7
2 30 15 10 8 25 80

Sample Output
87
100

*/