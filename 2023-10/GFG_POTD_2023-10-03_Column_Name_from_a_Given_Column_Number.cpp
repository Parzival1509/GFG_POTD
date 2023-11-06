// GFG POTD 2023/10/03
// Column Name from a Given Column Number
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string colName (long long n) {
        string ans = "";
        while(n > 0) {
            int rem = (n - 1) % 26;
            char ch = 'A' + rem;
            ans = ch + ans;
            n = (n - 1) / 26;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution ob;
        cout << ob.colName (n) << '\n';
    }
}

/* Sample Input:
4
13
28
52
100

Sample Output:
M
AB
AZ
CV

*/