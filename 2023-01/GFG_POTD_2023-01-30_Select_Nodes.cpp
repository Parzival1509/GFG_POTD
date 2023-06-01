// GFG POTD 2023/01/30
// Select Nodes
// Hard

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    void dfs(vector<vector<int>>& nodes, int src, int act, vector<pair<int, int>>& dp) {
        for(auto & i: nodes[src])
            if(i != act) dfs(nodes, i, src, dp);
        for(auto& i: nodes[src])
            if(i != act) {
                dp[src].first += dp[i].second;
                dp[src].second += min(dp[i].first, dp[i].second);
            }
    }
    
    int countVertex(int N, vector<vector<int>>edges) {
        vector<vector<int>> nodes(N);
        for(auto & e : edges) {
            nodes[e[0] - 1].push_back(e[1] - 1);
            nodes[e[1] - 1].push_back(e[0] - 1);
        }
        vector<pair<int, int>> dp(N, {0, 1});
        dfs(nodes, 0, 0, dp);
        return min(dp[0].first, dp[0].second);
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++) {
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 

/* Sample Input
2
6
1 2
1 3
2 4
3 5
3 6
3
1 2
1 3

Sample Output
2
1

*/