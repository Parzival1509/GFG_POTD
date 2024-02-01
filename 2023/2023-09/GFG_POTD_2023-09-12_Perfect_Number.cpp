// GFG POTD 2023/09/12
// Perfect Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPerfectNumber(long long N) {
        if(N == 1) return 0;
        
        long long count = 1, factor1, factor2;
        for(long long i = 2; i <= sqrt(N); i++)
            if(N % i == 0) {
                factor1 = i;
                factor2 = N / i;
                count += factor1 + factor2;
            }
        
        return count == N;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }

    return 0;
}

/* Sample Input:
2
6
10

Sample Output:
1
0

*/