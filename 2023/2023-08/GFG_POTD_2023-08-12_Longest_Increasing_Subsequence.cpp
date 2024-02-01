// GFG POTD 2023/08/12
// Longest Increasing Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(int n, int a[]) {
        vector<int> dp;
        dp.push_back(a[0]);
       
        for(int i = 1; i < n; i++)
            if(a[i]>dp[dp.size()-1])
                dp.push_back(a[i]);
            else {
                auto it = lower_bound(dp.begin(), dp.end(), a[i]);
                int ind = distance(dp.begin(), it);
                dp[ind] = a[i];
            }
       
       return dp.size();
    }
};

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
}


/* Sample Input:
3
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1
12
10 10 9 8 4 8 10 4 5 12 12 7

Sample Output:
6
3
4

*/