// GFG POTD 2023/11/29
// Euler Circuit and Path
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isEulerCircuit(int V, vector<int>adj[]) {
        int t = 0;
        for(int i = 0; i < V; i++) {
            int z = adj[i].size();
            if(z & 1) t++;
        }
        
        if(t == 0) return 2;
        if(t == 2) return 1;
        return 0;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.isEulerCircuit(V, adj);
        cout << ans << "\n";
    }

    return 0;
}

/* Sample Input:
2

3 3
0 1
0 2
1 2

3 2
0 1
0 2


Sample Output:
2
1

*/