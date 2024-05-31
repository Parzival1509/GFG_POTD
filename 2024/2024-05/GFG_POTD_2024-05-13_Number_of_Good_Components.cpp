// GFG POTD 2024/05/13
// Number of Good Components
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], int size, int &cv, bool &flag, vector<int> &vis) {
        vis[node] = 1;
        cv++;
        
        if(size != adj[node].size())
            flag = false;
            
        for(auto v: adj[node])
            if(!vis[v])
                dfs(v, adj, size, cv, flag, vis);
    }

    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> vis(v + 1), adj[v + 1];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
            
        int count = 0;
        for(int i = 1; i <= v; i++) {
            if(!vis[i]) {
                bool flag = true;
                int cv = 0;
                
                dfs(i, adj, adj[i].size(), cv, flag, vis);
                
                if(flag and cv == 1 + adj[i].size())
                    count++;
            }
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int e, v;
        cin >> e >> v;
        vector<vector<int>> edges(e, vector<int>(2));
        for(int i = 0; i < e; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);
        cout << res << endl;
    }
}

/* Sample Input
2

3 3
1 2
1 3
3 2

5 7
1 2
7 2
3 5
3 4
4 5


Sample Output
1
2

*/