// GFG POTD 2023/10/17
// Transitive Closure of a Graph
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph) {
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) {
                    if(i == j) graph[i][j] = 1;
                    if(graph[i][k] == 1 && graph[k][j] == 1)
                        graph[i][j] = 1;
                }
        
        return graph;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        vector<vector<int>> graph(N, vector<int> (N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0; j < N; j++)
            cin >> graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
4
1 1 0 1 
0 1 1 0 
0 0 1 1 
0 0 0 1
3
1 0 0
0 1 0
0 0 1

Sample Output:
1 1 1 1 
0 1 1 1 
0 0 1 1 
0 0 0 1 

1 0 0 
0 1 0 
0 0 1 


*/