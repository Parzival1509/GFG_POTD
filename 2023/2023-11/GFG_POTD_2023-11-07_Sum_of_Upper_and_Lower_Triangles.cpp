// GFG POTD 2023/11/07
// Sum of Upper and Lower Triangles
// Easy

#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> sumTriangles(const vector<vector<int>>& matrix, int n) {
        int up = 0, lo = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(j >= i) up += matrix[i][j];
                if(j <= i) lo += matrix[i][j];
            }

        return {up, lo};
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
            for( int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }

        Solution ob;
        vector<int> result = ob.sumTriangles(matrix, n);
        for(int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
3
6 5 4
1 2 5
7 9 7
2
1 2
3 4

Sample Output:
29 32 
7 8 

*/