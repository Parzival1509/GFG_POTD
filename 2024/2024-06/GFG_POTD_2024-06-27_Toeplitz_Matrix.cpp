// GFG POTD 2024/06/27
// Toeplitz Matrix
// Medium

#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>>& mat) {
    vector<int> temp = mat[0];
    for (int i = 1; i < mat.size(); i++) {
        temp.pop_back();
        temp.insert(temp.begin(), mat[i][0]);
        if (temp != mat[i])
            return false;
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        bool b = isToeplitz(a);
        if (b == true)
            cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}

/* Sample Input
3

4 7
6 4 6 7 3 0 0
10 6 4 6 7 3 0
2 10 6 4 6 7 3
3 2 10 6 4 6 7

3 3
6 7 8
4 6 7
1 4 6

2 3
1 2 3
4 5 6


Sample Output
true
true
false

*/