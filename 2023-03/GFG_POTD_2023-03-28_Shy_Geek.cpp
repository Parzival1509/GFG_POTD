// GFG POTD 2023/03/28
// Shy Geek
// Medium

#include<bits/stdc++.h>
using namespace std;

class Shop {
    vector<int> chocolates;
    int countOfCalls;

public:
    Shop() {
        countOfCalls = 0;
    }
    void addChocolate(int x) {
        chocolates.push_back(x);
    }
    long long get(int i) {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50) return -1;
        return chocolates[i];
    }
};

#define ll long long

class Solution {
public:
    Shop shop;

    Solution(Shop s) {
        this->shop = s;
    }

    ll find(int n, long k) {
        ll ans = 0;
        int lo = 0, hi = n-1;
        while(k > 0) {
            int mxPrice = 0;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                int price = shop.get(mid);
                if(price > k) hi = mid - 1;
                else {
                    mxPrice = price;
                    lo = mid + 1;
                }
            }
            if(mxPrice == 0) break;
            ans += k / mxPrice;
            k = k % mxPrice;
            lo = 0;
        }
        return ans;
    }
};

int main() {
    int t;
    scanf("%d ",&t);
    while(t--) {
        int n;
        scanf("%d", &n);
        ll k;
        cin >> k;
        Shop shop;
        for(int i = 0; i<n; i++) {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        Solution obj(shop);
        ll res = obj.find(n, k);
        cout<<res<<endl;
    }
}

/* Sample Input:
3
3 5
2 4 6
4 9
1 2 3 4
10 35
1 2 4 5 6 8 9 10 16 20

Sample Output:
1
3
3

*/