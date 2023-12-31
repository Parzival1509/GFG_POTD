// GFG POTD 2023/12/20
// Modified Game of Nim
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinner(int n, int a[]) {
        if(n % 2 == 0) return 1;
        
        int val = 0;
        for(int i = 0; i < n; i++)
            val ^= a[i];
            
        return val == 0? 1: 2;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.findWinner(n, A) << "\n";
    }
    return 0;
}

/* Sample Input:
2
3
3 2 3
2
3 3

Sample Output:
2
1

*/