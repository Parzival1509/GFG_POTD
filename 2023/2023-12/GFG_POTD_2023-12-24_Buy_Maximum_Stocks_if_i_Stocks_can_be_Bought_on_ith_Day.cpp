// GFG POTD 2023/12/24
// Buy Maximum Stocks if i Stocks can be Bought on ith Day
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> pr;
        for(int i = 0; i < n; i++)
            pr.push_back({price[i], i + 1});

        sort(pr.begin(), pr.end());
        int ans = 0;

        for(auto p: pr) {
            int a = p.first, b = p.second;
            if(k >= a * b) {
                ans += b;
                k -= a * b;
            }
            else {
                ans += k / a;
                break;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int price[n];
        for(int i = 0 ; i < n; i++)
            cin >> price[i];
        Solution ob;
        int ans = ob.buyMaximumProducts(n, k, price);
        cout << ans << endl;
    }

    return 0;
}

/* Sample Input:
2
3 45
10 7 19
3 100
7 10 4

Sample Output:
4
6

*/