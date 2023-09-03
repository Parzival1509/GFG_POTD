// GFG POTD 2023/08/22
// Make Matrix Beautiful
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinOpeartion(vector<vector<int> > matrix, int n) {
        vector<int> sum_row(n, 0), sum_col(n, 0);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                sum_row[i] += matrix[i][j];
                sum_col[i] += matrix[j][i];
            }
        
        int maxi_row = *max_element(sum_row.begin(), sum_row.end());
        int maxi_col = *max_element(sum_col.begin(), sum_col.end());
        
        int ans_r = 0;
        for(auto it: sum_row)
            ans_r += maxi_row - it;
        
        int ans_c = 0;
        for(auto it: sum_col)
            ans_c += maxi_col - it;
        
        return max(ans_r,ans_c);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix (n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
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
4 2 3
3 2 1

Sample Output:
4
6

*/