// GFG POTD 2024/05/30
// String Subsequence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string s1, string s2) {
        int n = s1.length(), m = s2.length(), mod = 1e9 + 7;
        vector<int> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = m; j >= 1; j--)
                if (s1[i - 1] == s2[j - 1])
                    prev[j] = (prev[j - 1] + prev[j]) % mod;

        return prev[m];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        string s1, s2;
        getchar();
        getline(cin, s1);
        getline(cin, s2);
        cout << ob.countWays(s1, s2) << endl;
    }
    return 0;
}

/* Sample Input
2
geeksforgeeks
gks
problemoftheday
geek

Sample Output
4
0

*/