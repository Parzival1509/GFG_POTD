// GFG POTD 2023/06/30
// Is Binary Number Multiple of 3
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isDivisible(string s) {
        int sum = 0;
        for(auto i: s) {
            int x = i-'0';
            sum = ((sum * 2) + x) % 3;
        }
        
        return !(sum % 3);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
    return 0;
}

/* Sample Input:
2
0011
100

Sample Output:
1
0

*/