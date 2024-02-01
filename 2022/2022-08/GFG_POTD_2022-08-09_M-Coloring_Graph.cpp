// GFG POTD M-Coloring Problem

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
        for(int i=0; i<n; i++){
            if(i!=node && graph[i][node]==1 && color[i]==col)
                return false;
        }
        return true;
    }
    bool solve(int node, int color[], int m, int n, bool graph[101][101]){
        if(node==n)
            return true;
        for(int i=1; i<=m; i++){
            if(isSafe(node, color, graph, n, i)){
                color[node]=i;
                if(solve(node+1, color, m, n, graph))
                    return true;
                color[node]=0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(solve(0, color, m, n, graph))
            return true;
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

/* Sample Input
2
4 3 5
1 2
2 3
3 4
4 1
1 3
3 2 3
1 2
2 3
3 1

Sample Output
1
0

*/