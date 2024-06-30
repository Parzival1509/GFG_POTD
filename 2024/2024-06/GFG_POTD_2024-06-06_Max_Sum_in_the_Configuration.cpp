// GFG POTD 2024/06/06
// Max Sum in the Configuration
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long max_sum(int a[], int n) {
        long sum = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            prev += (long)i * a[i];
            sum += a[i];
        }

        long ans = prev;
        for (int i = 1; i < n; i++) {
            long curr = prev - (sum - a[i - 1]) + (long)a[i - 1] * (n - 1);
            prev = curr;
            ans = max(ans, curr);
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
    }
}

/* Sample Input
2
4
8 3 1 2
3
1 2 3

Sample Output
29
8

*/