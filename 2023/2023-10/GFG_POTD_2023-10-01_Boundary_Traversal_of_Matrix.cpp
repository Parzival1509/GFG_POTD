// GFG POTD 2023/10/01
// Boundary Traversal of Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m) {
        vector<int> ans;
        if(n == 1)
            for(int i = 0; i < m; i++)
                ans.push_back(matrix[0][i]);
        else if(m == 1)
            for(int i = 0; i < n; i++)
                ans.push_back(matrix[i][0]);
        else {
            for(int i = 0; i < m; i++)
                ans.push_back(matrix[0][i]);
            for(int i = 1; i < n; i++)
                ans.push_back(matrix[i][m - 1]);
            for(int i = m - 2; i >= 0; i--)
                ans.push_back(matrix[n - 1][i]);
            for(int i = n - 2; i > 0; i--)
                ans.push_back(matrix[i][0]);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> matrix[i][j];

        vector<int> ans = ob.boundaryTraversal(matrix, n, m);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 4
12 11 10 9
8 7 6 5
4 3 2 1

Sample Output:
1 2 3 4 8 12 16 15 14 13 9 5 
12 11 10 9 5 1 2 3 4 8 

*/