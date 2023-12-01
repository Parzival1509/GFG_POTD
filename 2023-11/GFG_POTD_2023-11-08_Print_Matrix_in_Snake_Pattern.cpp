// GFG POTD 2023/11/08
// Print Matrix in Snake Pattern
// Easy

#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> snakePattern(vector<vector<int> > matrix) {   
        int n = matrix.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
            if(i & 1)
                for(int j = n - 1; j >= 0; j--)
                    ans.push_back(matrix[i][j]);
            else
                for(int j = 0; j < n; j++)
                    ans.push_back(matrix[i][j]);
                    
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n); 

        for(int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for(int i = 0; i < result.size(); ++i)
                cout << result[i] << " ";
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
2
3
45 48 54
21 89 87
70 78 15
2
1 2
3 4

Sample Output:
45 48 54 87 89 21 70 78 15 
1 2 4 3 

*/