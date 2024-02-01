// GFG POTD 2023/07/11
// Find kth Element of Spiral Matrix
// Medium

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
public:
    int findK(int matrix[MAX][MAX], int r, int c, int k) {
        vector<int> ans;
        int left = 0, right = c - 1;
        int top = 0, bottom = r - 1;
        
        while(top <= bottom && left <= right) {
            
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        
        return ans[k - 1];
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m, k = 0;
        cin >> n >> m >> k;
        int a[MAX][MAX];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        cout << ob.findK(a, n, m, k) << endl;
    }
}

/* Sample Input:
2

4 4 10
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 3 4
1 2 3
4 5 6
7 8 9


Sample Output:
13
6

*/