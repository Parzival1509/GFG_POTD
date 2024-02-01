// GFG POTD 2023/04/15
// Find Total Time Taken
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i]) != mp.end())
                ans += time[arr[i]-1];
            else {        
                ans++;
                mp[arr[i]]++;
            }
        }
        return ans-1;
    }
};

int main() {
    int T;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin>>n;
        vector<int> arr(n, 0), time(n, 0);
        for(auto &i: arr)
            cin>>i;
        for(auto &i: time)
            cin>>i;
        cout<<ob.totalTime(n, arr, time)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4
1 2 3 3
1 2 3 4
4
1 2 3 4
1 2 3 4
8
6 6 1 8 1 1 3 1
8 4 1 5 2 8 9 3

Sample Output:
5
3
35

*/