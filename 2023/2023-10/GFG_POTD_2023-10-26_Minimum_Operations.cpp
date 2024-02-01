// GFG POTD 2023/10/26
// Minimum Operations
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperation(int n) {
        if(n <= 2) return n;
        
        int ct = 0;
        while(n > 0) {
            if(n & 1) n--;
            else n >>= 1;
            ct++;
        }
        
        return ct;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
}

/* Sample Input:
3
5 7 8

Sample Output:
4
5
4

*/