// GFG POTD 2023/03/12
// Binary Matrix Having Maximum Number of 1s
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int n) {
        int i = 0, j = n-1, row = 0, ones = 0;
        while(i<n && j>=0) {
            if(mat[i][j] == 1) {
                row = i;
                ones++;
                j--;
            }
            else i++;
        }
        return {row, ones};
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans)
            cout << val << " ";
        cout << endl;
    }
}

/* Sample Input:
2
3
0 0 1
0 1 1
0 0 0
3
1 1 1
1 1 1
0 0 0

Sample Output:
1 2 
0 3 

*/