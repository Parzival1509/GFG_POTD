// GFG POTD 2023/08/23
// Find the String in Grid
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    bool existsInDirection(vector<vector<char>>& grid, int row, int col, string &word) {
        int n = grid.size(), m = grid[0].size(), len = word.length();
    
        if(grid[row][col] != word[0]) return false;
    
        for(int dir = 0; dir < 8; dir++) {
            int k, newRow = row + x[dir], newCol = col + y[dir];
    
            for(k = 1; k < len; k++) {
                if(newRow >= n || newRow < 0 || newCol >= m || newCol < 0)
                    break;
                if(grid[newRow][newCol] != word[k])
                    break;
    
                newRow += x[dir], newCol += y[dir];
            }
    
            if(k == len) return true;
        }
        
        return false;
    }

    vector<vector<int>>searchWord(vector<vector<char>> grid, string word) {
        vector<vector<int>> result;
        int n = grid.size(), m = grid[0].size();
    
        for(int row = 0; row < n; row++)
            for(int col = 0; col < m; col++)
                if(existsInDirection(grid, row, col, word))
                    result.push_back({row, col});
    
        return result;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char> (m, 'x'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];

        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        if(ans.size() == 0)
            cout<<"-1\n";
        else {
            for(auto i: ans) {
                for(auto j: i)
                    cout << j << " ";
                cout << "\n";
            }
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

3 3
abc
def
ghi
abc

4 3
abab
abeb
ebeb
abe

Sample Output:
0 0 

0 0 
0 2 
1 1 


*/