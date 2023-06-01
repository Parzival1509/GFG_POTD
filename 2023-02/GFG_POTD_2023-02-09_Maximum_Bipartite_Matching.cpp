// GFG POTD 2023/02/09
// Maximum Bipartite Matching
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> match, vis;
    bool solve(int p, vector<vector<int>> &g) {
        for(int j=0; j<g[0].size(); j++) {
            if(g[p][j] && !vis[j]) {
                vis[j] = 1;
                if(match[j]==-1 || solve(match[j], g)) {
                    match[j] = p;
                    return true;
                }
            }
        }
        return false;
    }
    
    int maximumMatch(vector<vector<int>> &g) {
        int p = g.size(), j = g[0].size(), ans = 0;
        match = vector<int>(j, -1);
        for(int i=0; i<p; i++) {
            vis=vector<int>(j, 0);
            if(solve(i, g)) ans++;
        }
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>>G(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> G[i][j];
        Solution obj;
        int ans = obj.maximumMatch(G);
        cout << ans << "\n";    
    }
    return 0;
}

/* Sample Input:
2
3 5 
1 1 0 1 1 
0 1 0 0 1 
1 1 0 1 1
6 2
1 1
0 1
0 1
0 1
0 1
1 0

Sample Output:
3
2

*/