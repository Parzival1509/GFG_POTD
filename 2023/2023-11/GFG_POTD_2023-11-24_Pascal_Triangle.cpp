// GFG POTD 2023/11/24
// Pascal Triangle
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1e9 + 7;

class Solution {
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>> r(n);

        for(int i = 0; i < n; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for(int j = 1; j < i; j++)
                r[i][j] = (r[i - 1][j - 1] + r[i - 1][j]) % mod;
        }
        
        return r[n - 1];
    }
};

void printAns(vector<long long> &ans) {
    for(auto &x: ans)
        cout << x << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }

    return 0;
}

/* Sample Input:
2
4
5

Sample Output:
1 3 3 1 
1 4 6 4 1 

*/