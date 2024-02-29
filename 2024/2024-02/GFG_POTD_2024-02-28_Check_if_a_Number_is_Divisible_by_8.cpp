// GFG POTD 2024/02/28
// Check if a Number is Divisible by 8
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DivisibleByEight(string s) {
        int n = s.size();
        if (n >= 3)
            return (stoi(s.substr(n - 3, 3)) % 8 == 0) ? 1 : -1;
        return (stoi(s) % 8 == 0) ? 1 : -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.DivisibleByEight(S) << "\n";
    }
}

/* Sample Input
2
16
54141111648421214584416464555

Sample Output
1
-1

*/