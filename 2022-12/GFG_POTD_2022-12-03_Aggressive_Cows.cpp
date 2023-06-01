// GFG POTD 2022/12/03
// Aggresive Cows
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int lo=0, hi=stalls[n-1], ans=0;
        while(lo <= hi) {
            int mid = lo+(hi-lo)/2;
            if(isValid(stalls, k, mid)) {
                ans = max(ans, mid);
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
    
    bool isValid(vector<int> a, int k, int dis) {
        int pidx=0;
        for(int i=1; i<a.size(); i++) {
            if(a[i]-a[pidx] >= dis) {
                k--;
                pidx = i;
            }
        }
        return k<=1;
    }
};

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;
    }

    return 0;
}

/* Sample Input
2
5 3
1 2 4 8 9
5 3
10 1 2 7 5

Sample Output
3
4

*/