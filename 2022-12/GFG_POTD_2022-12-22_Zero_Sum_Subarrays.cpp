// GFG POTD 2022/12/22
// Zero Sum Subarrays
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    ll int findSubarray(vector<long long int> &arr, int n ) {
        ll sum=0, ans=0;
        unordered_map<ll, ll> mp;
        mp[0]=1;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
    return 0;
}

/* Sample Input
2
6
0 0 5 5 0 0
10
6 -1 -3 4 -2 2 4 6 -12 -7

Sample Output
6
4

*/