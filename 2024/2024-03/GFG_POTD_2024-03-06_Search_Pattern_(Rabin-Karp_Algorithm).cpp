// GFG POTD 2024/03/06
// Search Pattern (Rabin-Karp Algorithm)
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string pattern, string text) {
        int n = text.size(), m = pattern.size();
        vector<int> res;

        // // Approch 1:
        // for (int i = 0; i < n - m + 1; i++)
        //     if (pattern == text.substr(i, m))
        //         res.push_back(i + 1);

        // Approach 2: Rabin-Karp Algorithm
        int d = 256, q = INT_MAX;
        int t0 = 0, p0 = 0, x = 1;
        
        for (int i = 0; i < m; i++) {
            t0 = (t0 * d + text[i]) % q;
            p0 = (p0 * d + pattern[i]) % q;
        }
        
        for (int i = 0; i < m - 1; i++)
            x = (x * d) % q;

        int i = 0;
        while (i <= n - m) {
            if (t0 == p0) {
                int j = 0;
                while (j < m && text[i + j] == pattern[j])
                    j++;
                if (j == m)
                    res.push_back(i + 1);
            }
            if (i < n - m) {
                t0 = ((t0 - text[i] * x) * d + text[i + m]) % q;
                if (t0 < 0)
                    t0 = t0 + q;
            }
            i++;
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
birthdayboy birth
geeksforgeeks geek

Sample Output
1
1 9

*/