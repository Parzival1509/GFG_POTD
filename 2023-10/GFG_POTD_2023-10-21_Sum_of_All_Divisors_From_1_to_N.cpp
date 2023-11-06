// GFG POTD 2023/10/21
// Sum of All Divisors From 1 to N
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumOfDivisors(int n) {
        long long sum = 0;
        for(int i = 1; i <= n; i++)
            sum += i * (n / i);
            
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.sumOfDivisors(n) << endl;
    }
    return 0;
}

/* Sample Input:
2
4 5

Sample Output:
15
21

*/