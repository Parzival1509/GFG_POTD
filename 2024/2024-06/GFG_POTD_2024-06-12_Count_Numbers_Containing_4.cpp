// GFG POTD 2024/06/12
// Count Numbers Containing 4
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDigitFour(int num) {
        string str = to_string(num);
        return str.find('4') != string::npos;
    }

    int countNumberswith4(int n) {
        int ct = 0;
        for (int i = 1; i <= n; ++i)
            if (containsDigitFour(i))
                ct++;

        return ct;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int n;
        cin >> n;
        cout << ob.countNumberswith4(n) << endl;
    }
    return 0;
}

/* Sample Input
2
9
44

Sample Output
1
9

*/