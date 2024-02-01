// GFG POTD 2023/08/07
// Solve the Sudoku
// Hard

#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

class Solution {
public:
    bool isValid(int grid[N][N], int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(grid[i][col] == c) return false;
            if(grid[row][i] == c) return false;
            if(grid[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }

        return true;
    }
    
    bool SolveSudoku(int grid[N][N]) { 
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(grid[i][j] == 0) {
                    for(char c = 1; c <= 9; c++) {
                        if(isValid(grid, i, j, c)) {
                            grid[i][j] = c;
                            if(SolveSudoku(grid) == true) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }

        return true;
    }
    
    void printGrid (int grid[N][N]) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cout << grid[i][j] << ' ';
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int grid[N][N];
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                cin >> grid[i][j];
                
        Solution ob;
        if(ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else cout << "No solution exists";  
        cout << endl << endl;
    }
    return 0;
}

/* Sample Input:
2

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

3 6 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Sample Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9 

No solution exists

*/