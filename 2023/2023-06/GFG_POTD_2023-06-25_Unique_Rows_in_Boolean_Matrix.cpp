// GFG POTD 2023/06/25
// Unique Rows in Boolean Matrix
// Easy

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i = 0; i < row; i++) {
            vector<int> tmp(col);
            for(int j = 0; j < col; j++)
                tmp[j] = M[i][j];
            if(s.find(tmp) == s.end()) {
                ans.push_back(tmp);
                s.insert(tmp);
            }
        }
        
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for(int i = 0; i < vec.size(); i++) {
            for(int x: vec[i])
                cout << x << " ";
            cout << endl;
        }
        cout << endl;
    }
}

/* Sample Input:
2

3 4
1 1 0 1
1 0 0 1
1 1 0 1

2 4
0 0 0 1
0 0 0 1

Sample Output:
1 1 0 1
1 0 0 1

0 0 0 1

*/