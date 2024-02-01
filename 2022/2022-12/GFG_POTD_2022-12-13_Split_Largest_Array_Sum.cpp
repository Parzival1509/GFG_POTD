// GFG POTD 2022/12/13
// Split Largest Array Sum
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(int a[], int n, int mid) {
        int sum=0, m=1;
        for(int i=0; i<n; i++) {
            if(sum+a[i] > mid) {
                sum = a[i];
                m++;
            }
            else
                sum += a[i];
        }
        return m;
    }

    int splitArray(int a[] ,int n, int k) {
        int lo = *max_element(a, a+n);
        int hi = accumulate(a, a+n, 0);
        // cout<<lo<<' '<<hi<<endl;
        int ans=lo;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            int m = numOfSubarrays(a, n, mid);
            if(m>k)
                lo = mid+1;
            else {
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        int arr[N];
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.splitArray(arr, N, K);
        cout<<"\n";
    }
    return 0;
}

/* Sample Input
3
3 2
1 1 2
4 3
1 2 3 4
4 1
4 8 9 2

Sample Output
2
4
23

*/