// GFG POTD 2024/08/26
// Wildcard Matching
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int i, int j, string p, string s, vector<vector<int>>& dp) {
        int n = p.size(), m = s.size();

        if (i == n || j == m) {
            if (i == n) {
                if (j < m)
                    return 0;
                return true;
            }
            if (j == m) {
                while (i < n) {
                    if (p[i++] != '*')
                        return 0;
                }
                return 1;
            }
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[i] == s[j] || p[i] == '?')
            return dp[i][j] = rec(i + 1, j + 1, p, s, dp);

        if (p[i] == '*')
            return dp[i][j] = rec(i + 1, j + 1, p, s, dp) || rec(i, j + 1, p, s, dp) || rec(i + 1, j, p, s, dp);

        return dp[i][j] = 0;
    }

    int wildCard(string pattern, string str) {
        int n = pattern.size(), m = str.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return rec(0, 0, pattern, str, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

/* Sample Input
2
ba*a? baaabab
a*ab baaabab

Sample Output
1
0

*/