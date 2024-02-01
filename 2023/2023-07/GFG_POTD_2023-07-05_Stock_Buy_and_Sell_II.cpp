// GFG POTD 2023/07/05
// Stock Buy and Sell II
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int profit = 0;
        for(int i = 1; i < n; i++)
            if(prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> prices(n, 0);
        for(int &i: prices)
            cin >> i;
        Solution ob;
        cout << ob.stockBuyAndSell(n, prices) << endl;
    }
}

/* Sample Input:
3
4
3 4 1 5
5
1 3 5 7 9
7
100 180 260 310 40 535 695

Sample Output:
5
8
865

*/