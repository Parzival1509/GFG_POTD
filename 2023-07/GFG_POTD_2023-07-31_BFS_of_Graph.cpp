// GFG POTD 2023/07/31
// BFS of Graph
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V + 1);
        vector<int> ans;
        queue<int> to_visit;
        to_visit.push(0);
        
        while(!to_visit.empty()) {
            int node = to_visit.front();
            to_visit.pop();
            visited[node] = true;
            ans.push_back(node);
            
            for(auto &nod: adj[node])
                if(!visited[nod]) {
                    to_visit.push(nod);
                    visited[nod] = true;
                }
        }
        
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2

5 4
0 1 
0 2
0 3 
2 4

3 2
0 1
0 2

Sample Output:
0 1 2 3 4 
0 1 2 

*/