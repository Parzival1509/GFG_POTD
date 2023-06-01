// GFG POTD 2023/03/21
// Taxi Booking
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, int cur, vector<int> &pos, vector<int> &time) {
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
            ans = min(ans, abs(cur - pos[i]) * time[i]);
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, cur;
        cin>>N>>cur;
        vector<int> pos(N), time(N);
        for(int i=0; i<N; i++)
            cin>>pos[i];
        for(int i=0; i<N; i++)
            cin>>time[i];
        Solution ob;
        cout<<ob.minimumTime(N, cur, pos, time)<<endl;
    }
}

/* Sample Input:
2
2 1
1 6
10 3
3 4
1 5 6
2 3 1

Sample Output:
0
2

*/