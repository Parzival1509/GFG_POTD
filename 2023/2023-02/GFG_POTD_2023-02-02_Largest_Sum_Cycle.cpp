// GFG POTD 2023/02/02
// Largest Sum Cycle
// Hard

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    ll ans = -1;
    void dfs(int node, ll sum, vector<int> &adj, vector<int> &pref, vector<int> &vis){
        if(node == -1 or (vis[node] and pref[node] == -1)) return;
        if(vis[node] and pref[node] != -1) {
            ans = max(ans, sum-pref[node]);
            return;
        }
        vis[node] = true;
        pref[node] = sum;
        dfs(adj[node], sum+node, adj, pref, vis);
        pref[node] = -1;
    }

    ll largestSumCycle(int N, vector<int> edge) {
        vector<int> pref(N, -1), vis(N);
        for(int node=0; node<N; node++)
            dfs(node, 0, edge, pref, vis);
        return ans;
    }
};

signed main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        vector<int> Edge(N);
        for(int i=0; i<N; i++)
            cin>>Edge[i];
        Solution obj;
        ll ans = obj.largestSumCycle(N, Edge);
        cout<<ans<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
1 2 0 -1
4
2 0 -1 2

Sample Output:
3
-1

*/