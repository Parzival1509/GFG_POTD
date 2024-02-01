// GFG POTD 2023/08/01
// DFS of Graph
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &res, vector<int>&vis){
        vis[node] = 1;
        res.push_back(node);
        for(auto it: adj[node])
            if(!vis[it])
                dfs(it, adj, res, vis);
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> vis(V, 0);
        dfs(0, adj, res, vis);
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2

5 4
0 2
0 3
0 1
2 4

4 3
0 1
0 3
1 2

Sample Output:
0 2 4 3 1 
0 1 2 3 

*/