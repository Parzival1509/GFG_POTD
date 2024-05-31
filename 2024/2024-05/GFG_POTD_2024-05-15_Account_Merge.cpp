// GFG POTD 2024/05/15
// Account Merge
// Hard

#include <bits/stdc++.h>
using namespace std;

class DisjointSetSize {
    vector<int> size;
    vector<int> parent;

public:
    DisjointSetSize(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSetSize ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                if (mp.count(s)) {
                    int p1 = mp[s];
                    int p2 = i;
                    ds.unionBySize(p1, p2);
                } else
                    mp[s] = i;
            }

        unordered_map<int, vector<string>> mp2;
        for (auto it : mp) {
            int p1 = ds.findUPar(it.second);
            mp2[p1].push_back(it.first);
        }

        vector<vector<string>> ans;
        for (auto& it : mp2) {
            sort(it.second.begin(), it.second.end());
            int ind = mp[it.second[0]];
            it.second.insert(it.second.begin(), accounts[ind][0]);
            ans.push_back(it.second);
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
        vector<vector<string>> accounts;
        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;
            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << "," << " ";
                else cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else cout << "]";
        }
        cout << "]" << endl << endl;
    }
}

/* Sample Input
2

4
3
John johnsmith@mail.com john_newyork@mail.com
3
John johnsmith@mail.com john00@mail.com
2
Mary mary@mail.com
2
John johnnybravo@mail.com

5
4
Gabe Gabe00@m.co Gabe3@m.co Gabe1@m.co
4
Kevin Kevin3@m.co Kevin5@m.co Kevin0@m.co
4
Ethan Ethan5@m.co Ethan4@m.co Ethan0@m.co
4
Hanzo Hanzo3@m.co Hanzo1@m.co Hanzo0@m.co
4
Fern Fern5@m.co Fern1@m.co Fern0@m.co

Sample Output
[[John, john00@mail.com, john_newyork@mail.com, johnsmith@mail.com], 
[John, johnnybravo@mail.com], 
[Mary, mary@mail.com]]

[[Ethan, Ethan0@m.co, Ethan4@m.co, Ethan5@m.co], 
[Fern, Fern0@m.co, Fern1@m.co, Fern5@m.co], 
[Gabe, Gabe00@m.co, Gabe1@m.co, Gabe3@m.co], 
[Hanzo, Hanzo0@m.co, Hanzo1@m.co, Hanzo3@m.co], 
[Kevin, Kevin0@m.co, Kevin3@m.co, Kevin5@m.co]]


*/