// GFG POTD 2023/04/22
// Smaller Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<ll> smallerSum(int n, vector<int> &arr) {
        vector<ll> ans(n);
        vector<int> temp = arr;
        unordered_map<int, ll> m;
        
        sort(temp.begin(), temp.end());
        
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(m.find(temp[i]) == m.end())
                m[temp[i]] = sum;
            sum += temp[i];
        }
        
        for(int i = 0; i < n; i++)
            ans[i] = m[arr[i]];
        
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
        vector<long long> ans = ob.smallerSum(n, arr);
        for(int i=0; i<n; i++)
            if(i != n-1) cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
    }
    return 0;
}

/* Sample Input:
3
3
1 2 3
2
4 4
5
3 5 1 8 9

Sample Output:
0 1 3
0 0
1 4 0 9 17

*/