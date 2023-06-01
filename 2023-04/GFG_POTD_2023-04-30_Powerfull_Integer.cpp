// GFG POTD 2023/04/30
// Powerfull Integer
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int powerfullInteger(int n, vector<vector<int>> &intervals, int k) {
        int mx = INT_MIN;
        for(int i=0; i<n; i++)
            mx = max(mx, intervals[i][1]);
            
        vector<int> v(mx+3, 0);
        for(int i=0; i<n; i++) {
            v[intervals[i][0]] += 1;
            v[intervals[i][1] + 1] -= 1;
        }
        
        int ans = -1;
        for(int i=1; i<mx+3; i++) {
             v[i] = v[i-1] + v[i];
             if(v[i] >= k) ans = i;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n;
        vector<vector<int>> intervals(n, vector<int> (2));
        for(int i=0; i<n; i++)
            cin>>intervals[i][0]>>intervals[i][1];
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n, intervals, k)<<endl;
    }
    return 0;
}

/* Sample Input:
3

3
1 3
4 6
3 4
2

4
1 4
12 45
3 8
10 12
3

5
16 21
5 8
12 17
17 29
9 24
3

Sample Output:
4
-1
21

*/