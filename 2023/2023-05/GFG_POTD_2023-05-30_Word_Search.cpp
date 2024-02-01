// GFG POTD 2023/05/30
// Word Search
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int i, int j, int ind) {
        if(ind >= word.size()) return true;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[ind])
            return false;
        
        board[i][j] = '0';
        bool up = check(board, word, i - 1, j, ind + 1);
        bool down = check(board, word, i + 1, j, ind + 1);
        bool left = check(board, word, i, j - 1, ind + 1);
        bool right = check(board, word, i, j + 1, ind + 1);
        
        return up || down || left || right;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(check(board, word, i, j, 0))
                    return true;
                    
        return false;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>>board(n, vector<char>(m, '*'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if(ans)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}

/* Sample Input:
2
3 4 
a g b c 
q e e l 
g b k s 
geeks
3 4
a b c e
s f c s
a d e e
sabfs

Sample Output:
1
0

*/