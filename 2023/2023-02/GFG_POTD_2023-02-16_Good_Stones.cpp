// GFG POTD 2023/02/16
// Good Stones
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int i, vector<int> &arr, vector<int> &vis, vector<int> &dp) {
        if(i >= arr.size()) return 1;
        if(vis[i] == 1) return 0;
        if(dp[i] != -1) return dp[i];
        vis[i] = 1;
        bool f =  check(i+arr[i], arr, vis, dp);
        vis[i] = 0;
        return dp[i] = f;
    }
    
    int goodStones(int n, vector<int> &arr) {
        vector<int> vis(n, 0), dp(n, -1);
        int res = 0;
        for(int i=0; i<n; i++) {
            bool f = check(i, arr, vis, dp);
            if(f) res++;
        }
        return res;
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
        cout<<ob.goodStones(n, arr)<<endl;
    }
    return 0;
}

/* Sample Input:
2
7
2 3 -1 2 -2 4 1
6
1 0 -3 0 -5 0

Sample Output:
3
2

*/