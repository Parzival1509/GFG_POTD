// GFG POTD 2024/03/19
// Possible Paths in a Tree
// Hard

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    int unionBySize(int u, int v) {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        int ans = size[ulp_u] * size[ulp_v];
        
        if (ulp_u == ulp_v) return ans;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int>& queries) {
        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            edges[i][0] = wt;
            edges[i][1] = u;
            edges[i][2] = v;
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(n + 1);
        
        map<int, int> mp;
        int val = 0;
        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][1];
            int v = edges[i][2];
            int wt = edges[i][0];
            mp[wt] = ds.unionBySize(u, v) + val;
            val = mp[wt];
        }

        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            auto it = mp.upper_bound(queries[i]);
            if (it != mp.begin()) {
                it--;
                ans[i] = it->second;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n - 1, vector<int>(3, 0));
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < 3; j++)
                cin >> edges[i][j];
        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++)
            cin >> queries[i];

        Solution obj;
        vector<int> ans = obj.maximumWeight(n, edges, q, queries);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input
2

3
1 2 1
2 3 4
1
3

7
1 2 3
2 3 1
2 4 9
3 6 7
3 5 8
5 7 4
3
1 3 5

Sample Output
1 
1 3 4 

*/