// GFG POTD 2024/01/30
// LCS of Three Strings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {   
public:
    int dp[21][21][21];
    
    int solve(string A, string B, string C, int i, int j, int k) {
        if(i < 0 || j < 0 || k < 0) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(A[i] == B[j] && B[j] == C[k])
            return dp[i][j][k] = 1 + solve(A, B, C, i - 1, j - 1, k - 1);

        return dp[i][j][k] = max(solve(A, B, C, i - 1, j, k), max(solve(A, B, C, i, j - 1, k), solve(A, B, C, i, j, k - 1)));
    }

    int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
        for(int i = 0; i <= n1; i++)
            for(int j = 0; j <= n2; j++)
                for(int k = 0; k <= n3; k++)
                    dp[i][j][k] = -1;
        
        return solve(A, B, C, n1 - 1, n2 -1 , n3 - 1);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n1, n2, n3;
        string A, B, C;
        cin >> n1 >> n2 >> n3 >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}

/* Sample Input:
2
5 8 13
geeks geeksfor geeksforgeeks
4 4 4
abcd efgh ijkl

Sample Output:
5
0

*/