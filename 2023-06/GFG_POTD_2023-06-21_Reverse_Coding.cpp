// GFG POTD 2023/06/21
// Reverse Coding
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfNaturals(int n) {
        long long ans = 1LL * n * (n + 1) / 2;
        return ans % (1000000007);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}

/* Sample Input:
2
4
6

Sample Output:
10
21

*/