// GFG POTD 2023/09/04
// Replace O's with X's
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int ii, int jj, int& n, int& m) {
        return (ii >= 0 && jj >= 0 && ii < n && jj < m); 
    }

    bool isBoundary(int i, int j, int &n, int &m) {
        return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
    }

    void setNotClosed(int i, int j, int& n, int& m, vector<vector<char>>& mat) {
        mat[i][j] = 'N';

        for(int d = 0; d < 4; ++d) {
            int ii = dx[d] + i;
            int jj = dy[d] + j;
            if(isValid(ii, jj, n, m) && mat[ii][jj] == 'O')
                setNotClosed(ii, jj, n, m, mat);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(isBoundary(i, j, n, m) && mat[i][j] == 'O')
                    setNotClosed(i, j, n, m, mat);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 'O')
                    mat[i][j] = 'X';
                else if(mat[i][j] == 'N')
                    mat[i][j] = 'O';
            }
        }

        return mat;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char> (m, '.'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
3

4 5
X X X X X
O X X X O
O X X O X
X X X O O

5 4
X X X X
X O X X
X O O X
X O X X
X X O O

5 4
X O X X
X O X X
X O O X
X O X X
X X O O

Sample Output:
X X X X X 
O X X X O 
O X X O X 
X X X O O 

X X X X 
X X X X 
X X X X 
X X X X 
X X O O 

X O X X 
X O X X 
X O O X 
X O X X 
X X O O 


*/