// GFG POTD 2023/03/08
// Max Min Height
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool check(vector<int> &arr, int days, int water, ll h, int n) {
        vector<ll> waterSupply(n, 0);
        if(arr[0] < h) {
            waterSupply[0] = h - arr[0];
            days -= (h - arr[0]);
        }
        if(days < 0) return false;
        
        for(int i=1; i<n; i++) {
            waterSupply[i] = waterSupply[i-1];
            int actualHeight = arr[i];
            
            if(i >= water) actualHeight += (waterSupply[i] - waterSupply[i - water]);
            else actualHeight += waterSupply[i];
            
            if(actualHeight < h) {
                waterSupply[i] += (h - actualHeight);
                days -= (h - actualHeight);
            }
            if(days < 0) return false;
        }
        return true;
    }
        
    ll maximizeMinHeight(int n, int k, int w, vector<int> &a) {
        ll ans = -1, lo = (*min_element(a.begin(), a.end())), hi = INT_MAX;
        while(lo <= hi) {
            int mid = (hi + lo) / 2;
            if(check(a, k, w, mid, n)) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}

/* Sample Input:
2
6 2 3
2 2 2 2 1 1
2 5 1
5 8

Sample Output:
2
9

*/