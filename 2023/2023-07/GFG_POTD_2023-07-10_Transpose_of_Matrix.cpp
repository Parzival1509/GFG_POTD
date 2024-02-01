// GFG POTD 2023/07/09
// Transpose of Matrix
// Easy

#include <bits/stdc++.h> 
using namespace std;

class Solution {   
public:
    void transpose(vector<vector<int>>& matrix, int n) { 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int> (n)); 
        for(int i = 0; i < n; i++)
            for( int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution ob;
        ob.transpose(matrix, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
4
1 1 1 1 
2 2 2 2 
3 3 3 3 
4 4 4 4
2
1 2
-9 -2

Sample Output:
1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 

1 -9 
2 -2 


*/