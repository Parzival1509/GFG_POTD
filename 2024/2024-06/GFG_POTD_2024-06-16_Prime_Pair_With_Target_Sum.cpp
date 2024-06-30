// GFG POTD 2024/06/16
// Prime Pair With Target Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getPrimes(int n) {
        vector<int> ans = {-1, -1};
        if (n < 2)
            return ans;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++)
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;

        for (int i = 2; i <= n / 2; i++)
            if (isPrime[i] && isPrime[n - i]) {
                ans = {i, n - i};
                break;
            }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.getPrimes(n);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
3
10

Sample Output
-1 -1 
3 7 

*/