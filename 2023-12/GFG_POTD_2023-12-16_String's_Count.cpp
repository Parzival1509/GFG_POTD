// GFG POTD 2023/12/16
// String's Count
// Easy

#include <bits/stdc++.h>
using namespace std;

long long countStr(long long n) {
    long long a = 1;    // all a
    long long b = 2 * n;    // (n - 1)a and 1b or (n - 1)a and 1c
    long long c = n * (n - 1) / 2;  // (n - 2)a + 2c
    long long d = n * (n - 1);  // (n - 2)a + 1b + 1c
    long long e = (n * (n - 1) * (n - 2)) / 2;  // (n - 3)a + 1b + 2c
    
    return a + b + c + d + e;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        cout << countStr(n) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
1
2
3

Sample Output:
3
8
19

*/