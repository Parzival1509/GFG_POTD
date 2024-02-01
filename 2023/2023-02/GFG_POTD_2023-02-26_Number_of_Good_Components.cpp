// GFG POTD 2023/02/26
// Number of Good Components
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    int dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, unordered_map<int, int> &cnt) {
        vis[node] = true;
        int nodes = 1;
        for(auto it: adj[node]) {
            cnt[node]++;
            if(!vis[it]) nodes += dfs(it, vis, adj, cnt);
        }
        return nodes;
    }

public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V+1, false);
        int ans = 0;
        for(int i=1; i<=V; i++) {
            if(!vis[i]) {
                unordered_map<int, int> cnt;
                int get = dfs(i, vis, adj, cnt);
                get--;
                bool flag = true;
                for(auto it: cnt) {
                    if(it.second != get) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}

/* Sample Input:
3
3 4
1 3
3 4
1 4

3 3
1 2
2 3
1 3

5 7
1 2
2 7
3 4
4 5
3 5

Sample Output:
2
1
2

*/