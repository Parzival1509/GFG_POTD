// GFG POTD 2023/12/18
// Game of XOR
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gameOfXor(int n, int a[]) {
        if(n % 2 == 0) return 0;

        int ans = a[0];
        for(int i = 2; i < n; i += 2)
            ans ^= a[i];

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin>>N;
        int A[N];
        for(int i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.gameOfXor(N, A) << endl;
    }

    return 0;
}

/* Sample Input:
2
2
1 2
3
1 2 3

Sample Output:
0
2

*/