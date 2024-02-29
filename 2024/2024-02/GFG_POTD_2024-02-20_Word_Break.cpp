// GFG POTD 2024/02/20
// Word Break
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordBreak(int n, string s, vector<string>& dictionary) {
        int ns = s.size();
        vector<bool> dp(ns + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < ns; i++) {
            if (!dp[i]) continue;

            string ss;
            for (int j = i; j < ns; j++) {
                ss += s[j];
                for (auto _ : dictionary)
                    if (ss == _) {
                        dp[j + 1] = 1;
                        break;
                    }
            }
        }

        return dp[ns];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<string> dictionary;
        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dictionary.push_back(S);
        }
        Solution ob;
        cout << ob.wordBreak(n, s, dictionary) << "\n";
    }
}

/* Sample Input:
2
6 ilike
i like sam sung samsung mobile
6 ilikesamsung
i like sam sung samsung mobile

Sample Output:
1
1

*/