// GFG POTD Queries on a Matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> q) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i=0; i<q.size(); i++){
            int a=q[i][0];
            int b=q[i][1];
            int x=q[i][2];
            int y=q[i][3];
            for(int j=a; j<=x; j++)
                for(int k=b; k<=y; k++)
                    res[j][k]++;
        }
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}

/* Sample Input
1
6 6
4 0 5 3
0 0 3 4
1 2 1 2
1 1 2 3
0 0 3 1
1 0 2 4

Sample Output
2 2 1 1 1 0 
3 4 4 3 2 0 
3 4 3 3 2 0 
2 2 1 1 1 0 
1 1 1 1 0 0 
1 1 1 1 0 0 

*/