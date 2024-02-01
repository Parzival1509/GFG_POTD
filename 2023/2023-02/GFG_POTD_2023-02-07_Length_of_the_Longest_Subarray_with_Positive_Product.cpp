// GFG POTD 2023/02/07
// Length of the longest subarray with positive product
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int> &arr,int n) {
        int ans = 0, st = 0, first_neg = -1, ct = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) {
                st = i+1;
                first_neg = -1;
                ct = 0;
                continue;
            }
            else if(arr[i] < 0) {
                ct++;
                if(first_neg == -1) first_neg = i;
            }

            if(ct&1) ans = max(ans, i-first_neg);
            else ans = max(ans, i-st+1);
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
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        int res = ob.maxLength(arr, n);
        cout<<res<<"\n";
    }
    return 0;
}

/* Sample Input:
3
5
0 1 -2 -3 4
5
-1 -2 0 1 2
10
1 -2 -3 0 -4 3 -6 7 -9 5

Sample Output:
4
2
5

*/