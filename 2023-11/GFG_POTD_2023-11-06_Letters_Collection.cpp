// GFG POTD 2023/11/06
// Letters Collection
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[]) {
        vector<int> ans;
        vector<int> x1 = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> y1 = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> x2 = {-2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2};
        vector<int> y2 = {-2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2};

        for(int i = 0; i < q; i++) {
            int sum = 0, dis = queries[i][0];
            int xx = queries[i][1], yy = queries[i][2];

            if(dis == 1) {
                for(int j = 0; j < 8; j++) {
                    int nx = xx + x1[j];
                    int ny = yy + y1[j];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                        sum += mat[nx][ny];
                }
            }
            else {
                for(int j = 0; j < 16; j++) {
                    int nx = xx + x2[j];
                    int ny = yy + y2[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                        sum += mat[nx][ny];
                }
            }

            ans.push_back(sum);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, q, ty, i, j;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];

        cin >> q;
        vector<int> queries[q];
        for(int k = 0; k < q; k++) {
            cin >> ty >> i >> j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout << u << "\n";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

4 4
1 2 3 4
5 6 7 8
9 1 3 4
1 2 3 4
2
1 0 1
2 0 1

6 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36
1
2 3 2

Sample Output:
22
29

336


*/