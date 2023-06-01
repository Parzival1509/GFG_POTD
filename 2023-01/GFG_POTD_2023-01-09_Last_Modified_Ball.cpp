// GFG POTD 2023/01/09
// Last Modified Ball
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int> a) {
        for(int i=n-1; i>=0; i--)
        	if(a[i]<9) return i+1;
        return 1;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i=0; i<N; i++) cin >> A[i];
        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}

/* Sample Input
2
4
3 1 4 5
3
1 9 9

Sample Output
4
1

*/