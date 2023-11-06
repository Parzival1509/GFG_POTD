// GFG POTD 2023/10/18
// Eventual Safe States
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int node,vector<int> adj[], vector<int> &vis) {
        if(vis[node]) return false;
        
        vis[node] = 1;
        for(auto it: adj[node])
            if(check(it, adj, vis) == false)
                return false;
        
        vis[node] = 0;
        return true;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans, vis(V, 0);
        for(int i = 0; i < V; i++)
            if(check(i, adj, vis))
                ans.push_back(i);
            
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for(auto i: safeNodes)
            cout << i << " ";
        cout << endl;
    }
}

/* Sample Input:
2

7 7 
0 1
0 2
1 2
1 3
3 0
4 5
2 5

4 4
0 1
1 2
2 0
2 3

Sample Output:
2 4 5 6 
3 

*/