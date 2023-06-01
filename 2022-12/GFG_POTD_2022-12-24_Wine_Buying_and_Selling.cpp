// GFG POTD 2022/12/24
// Wine Buying and Selling
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wineSelling(vector<int>& arr, int n) {
        long long ans=0, pre=arr[0];
        for(int i=1; i<n; i++) {
            ans += abs(pre);
            pre += arr[i];
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
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        long long ans = ob.wineSelling(arr, n);
        cout<<ans<<endl;
    }
}

/* Sample Input
2
5
5 -4 1 -3 1
6
-100 -100 -100 100 100 100

Sample Output
9
900

*/