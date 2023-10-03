// GFG POTD 2023/09/05
// Print Adjacency List
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
        vector<vector<int>> adj(V);
        for(auto el: edges) {
            int u = el.first, v = el.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return adj;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> edges;
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i = 0; i < V; i++) {
            sort(adj[i].begin(), adj[i].end());
            for(auto it: adj[i])
                cout << it << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2

5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4

4 3
0 3
0 2
2 1

Sample Output:
1 4 
0 2 3 4 
1 3 
1 2 4 
0 1 3 

2 3 
2 
0 1 
0 


*/