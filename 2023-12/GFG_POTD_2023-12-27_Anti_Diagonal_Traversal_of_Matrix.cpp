// GFG POTD 2023/12/27
// Anti Diagonal Traversal of Matrix
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        int n = matrix.size();
        vector<int> ans;
        
        for(int t = 0; t < n; t++) {
            int j = t, i = 0;
            while(j >= 0)
                ans.push_back(matrix[i++][j--]);
        }
        
        for(int t = 1; t < n; t++) {
            int i = t, j = n - 1;
            while(i < n)
                ans.push_back(matrix[i++][j--]);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
2
1 2
3 4
3
1 2 3
4 5 6
7 8 9

Sample Output:
1 2 3 4 
1 2 4 3 5 7 6 8 9 

*/