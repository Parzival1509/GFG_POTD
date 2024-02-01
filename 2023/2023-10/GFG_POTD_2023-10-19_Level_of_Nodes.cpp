// GFG POTD 2023/10/19
// Level of Nodes
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nodeLevel(int V, vector<int> adj[], int X) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> vis(V, 0);
        vis[0] = 1;
        
        while(!q.empty()) {
            int level = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == X) return level;
            
            for(auto it: adj[node])
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({level + 1, it});
                }
        }
        
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int V, E, X;
        cin >> V >> E >> X;
        vector<int> adj[V];

        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        Solution obj;
        cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

/* Sample Input:
2
6 5 4
0 1
0 2
1 3
1 4
2 5
4 3 1
0 1
0 2
0 3

Sample Output:
2
1

*/