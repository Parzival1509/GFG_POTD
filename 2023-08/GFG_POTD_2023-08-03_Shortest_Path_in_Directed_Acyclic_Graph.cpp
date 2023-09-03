// GFG POTD 2023/08/03
// Shortest Path in Directed Acyclic Graph
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void explore(int i, int n, vector<vector<pair<int, int>>>& adj, vector<int>& shortPath, int currDist) {
        // Base case
        if(shortPath[i] != -1 && currDist > shortPath[i]) return;

        shortPath[i] = currDist;
        // Explore every adjacent node
        for(pair<int,int> edge : adj[i])
            explore(edge.first, n, adj, shortPath, currDist + edge.second);
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(N);
        for(vector<int>& edge: edges)
            adj[edge[0]].push_back({edge[1], edge[2]});
        
        vector<int> shortDist(N, -1);
        
        // Explore the graph, one index at a time
        explore(0, N, adj, shortDist, 0);
        return shortDist;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j = 0; j < 3; ++j) {
                int x;
                cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}

/* Sample Input:
2

4 2
0 1 2
0 2 1

6 7
0 1 2
0 4 1
4 5 4
4 2 2
1 2 3
2 3 6
5 3 1

Sample Output:
0 2 1 -1 
0 2 3 6 1 5 

*/