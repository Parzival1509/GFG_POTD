// GFG POTD 2023/08/13
// Nth Fibonacci Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthFibonacci(int n) {
        int mod = 1e9 + 7;
        int arr[n + 1];
        arr[0] = 0, arr[1] = 1;
        for(int i = 2; i <= n; i++)
            arr[i] = ((arr[i - 1] % mod) + (arr[i - 2] % mod)) % mod;
        return arr[n];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

/* Sample Input:
3
2 5 17

Sample Output:
1
5
1597

*/