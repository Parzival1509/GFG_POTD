// GFG POTD 2022/12/31
// Find Minimum Number of Laptops Required
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLaptops(int n, int start[], int end[]) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
            v.push_back({start[i], end[i]});
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(pq.empty() || pq.top()>v[i].first)
                pq.push(v[i].second);
            else {
                pq.pop();
                pq.push(v[i].second);
            }
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}

/* Sample Input
2
3
1 2 3
4 4 6
3
1 5 2
2 6 3

Sample Output
3
1

*/