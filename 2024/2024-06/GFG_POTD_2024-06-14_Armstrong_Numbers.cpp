// GFG POTD 2024/06/14
// Armstrong Numbers
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string armstrongNumber(int n) {
        int num = n, sum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x * x * x;
            n = n / 10;
        }

        return (num == sum) ? "true" : "false";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

/* Sample Input
2
153
372

Sample Output
true
false

*/