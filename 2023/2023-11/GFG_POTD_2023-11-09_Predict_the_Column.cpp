// GFG POTD 2023/11/09
// Predict the Column
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int columnWithMaxZeros(vector<vector<int>>arr, int n) {
        int ans = -1, c = 0;

        for(int i = 0; i < n; i++) {
            int ct = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j][i] == 0) ct++;
                if(c < ct) {
                    c = ct;
                    ans = i;
                }
            }

            if(ct == n) break;
        }

        return ans;
    }
};

int main() {
    int testcase;
    cin >> testcase;
    while(testcase--) {
        int N;
        cin >> N;
        vector<vector<int>>arr (N, vector<int>(N, 0));

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> arr[i][j];
        
        Solution ob;
        cout << ob.columnWithMaxZeros(arr, N) << endl;
    }
    
    return 0;
}

/* Sample Input:
1
3
0 0 1
0 1 0
1 0 1

Sample Output:
0

*/