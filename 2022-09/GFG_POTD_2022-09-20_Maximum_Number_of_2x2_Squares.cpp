// GFG POTD 2022/09/20
// Maximum Number of 2x2 Squares
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int numberOfSquares(long long int base){
        return (base/2 - 1)*(base/2)/2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int base;
        cin >> base;
        Solution ob;
        cout << ob.numberOfSquares(base) << "\n";
    }
    return 0;
}

/* Sample Input
2
7 8

Sample Output
3
6

*/