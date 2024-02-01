// GFG POTD 2024/01/14
// Find Duplicate Rows in a Binary Matrix
// Medium

#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int m, int n) {
        vector<vector<int>> v;
        vector<int> ans;
        for(int r = 0; r < m; r++) {
            vector<int> cur(matrix[r].begin(), matrix[r].end());
            if(find(v.begin(), v.end(), cur) == v.end())
                v.push_back(cur);
            else ans.push_back(r);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row); 
        for(int i = 0; i < row; i++) {
            matrix[i].assign(col, 0);
            for( int j = 0; j < col; j++)
                cin >> matrix[i][j];
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
2 2
1 0
1 0
4 3
1 0 0
1 0 0
0 0 0
0 0 0

Sample Output:
1 
1 3 

*/