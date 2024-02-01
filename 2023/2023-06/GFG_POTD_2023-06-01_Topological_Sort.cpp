// GFG POTD 2023/06/01
// Topological Sort
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> deg(V);
        for(int i = 0; i < V; i++)
            for(auto j: adj[i])
                deg[j]++;
        
        queue<int> que;
        vector<int> ans;
        for(int i = 0; i < V;i++)
            if(deg[i] == 0)
                que.push(i);
        
        while(!que.empty()) {
            int node = que.front();  
            que.pop();
            
            ans.push_back(node);
            for(auto i: adj[node]) {
                deg[i]--;
                if(deg[i] == 0)
                    que.push(i);
            }
        }
        return ans;
    }
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/

int check(int V, vector <int> &res, vector<int> adj[]) {
    if(V != res.size()) return 0;
    
    vector<int> map(V, -1);
    for(int i = 0; i < V; i++)
        map[res[i]] = i;
    
    for(int i = 0; i < V; i++)
        for (int v : adj[i])
            if (map[i] > map[v]) return 0;

    return 1;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int E, N;
        cin >> E >> N;
        int u, v;
        vector<int> adj[N];
        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
    return 0;
}

/* Sample Input:
2

3 4
3 0
1 0
2 0

6 6
1 3
2 3
5 2
5 0
4 0
4 1

Sample Output:
1
1

*/