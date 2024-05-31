// GFG POTD 2024/05/16
// Divisibility Tree
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int total = 0;

    int solve(int curr, int prev = -1) {
        int ans = 0;
        for (auto i : adj[curr])
            if (i != prev) {
                int res = solve(i, curr);
                if (res % 2 == 0)
                    total++;
                else ans += res;
            }

        return ans + 1;
    }

    int minimumEdgeRemove(int n, vector<vector<int>> edges) {
        for (auto i : edges) {
            int s = i[0];
            int e = i[1];
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        solve(1);

        return total;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution obj;
        int ans = obj.minimumEdgeRemove(n, edges);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
10
2 1 
3 1 
4 3 
5 2 
6 1 
7 2 
8 6 
9 8 
10 8
4
2 1
4 2
1 3

Sample Output
2
1

*/