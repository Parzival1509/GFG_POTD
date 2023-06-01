// GFG POTD 2023/04/11
// Maximum Length
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int a, int b, int c) {
        int mx = max(max(a, b), c);
        if(mx <= 2*(a+b+c-mx+1)) return a+b+c;
        return -1;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        int ans = ob.solve(a, b, c);
        cout <<  ans << "\n";
    }
    return 0;
}

/* Sample Input:
2
3 3 3
11 2 2

Sample Output:
9
-1

*/