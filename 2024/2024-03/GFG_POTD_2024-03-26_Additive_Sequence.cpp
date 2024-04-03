// GFG POTD 2024/03/26
// Additive Sequence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumber(string& s, int i, int j) {
        int ans = 0;
        for (int k = i; k < j; k++)
            ans = ans * 10 + (s[k] - '0');
        
        return ans;
    }

    bool isAdditiveSequence(string s) {
        int n = s.length(), a, b, c, ct;

        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                a = getNumber(s, 0, j);
                b = getNumber(s, j, i);
                int k = i;
                ct = 0;
                c = 0;

                while (k < n && c < a + b) {
                    c = c * 10 + (s[k] - '0');
                    if (c == a + b) {
                        ct++;
                        a = b;
                        b = c;
                        c = 0;
                    }
                    k++;
                }

                if (ct > 0 && k == n && c == 0)
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        string s;
        cin >> s;
        bool result = ob.isAdditiveSequence(s);
        cout << result << endl;
    }
    return 0;
}

/* Sample Input
2
1235813
11235815

Sample Output
1
0

*/