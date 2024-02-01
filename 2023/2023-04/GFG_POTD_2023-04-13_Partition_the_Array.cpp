// GFG POTD 2023/04/13
// Partition the Array
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> pre;
    
    vector<ll> minMax(int l,int r) {
        int low = l, high = r-1;
        ll mn = 0, mx = pre[r] - pre[l-1];
        while(low <= high) {
           int mid = low + (high-low)/2;
           ll leftSum = pre[mid] - pre[l-1], rightSum = pre[r] - pre[mid];
           
           if(abs(rightSum - leftSum) < mx-mn) {
               mx = max(leftSum, rightSum);
               mn = min(leftSum, rightSum);
           }
           if(leftSum < rightSum) low = mid + 1;
           else high = mid- 1;
        }
        return {mn, mx};
    }
    
    ll minDifference(int N, vector<int> &A) {
        pre.resize(N+1);
        pre[0] = 0;
        for(int i = 1; i<=N; i++)
            pre[i] = pre[i-1] + A[i-1];
        
        ll ans = pre.back();        
        for(int i = 1;i<N-2;i++) {
            vector<ll> l = minMax(1, i+1), r = minMax(i+2, N);
            ans = min({ans, max(l[1], r[1]) - min(l[0], r[0])});
        }
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin>>i;
        cout<<ob.minDifference(n, arr)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5
4 2 2 5 1
4
4 4 4 4

Sample Output:
4
0

*/