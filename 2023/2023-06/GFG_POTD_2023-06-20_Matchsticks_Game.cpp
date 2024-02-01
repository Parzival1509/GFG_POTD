// GFG POTD 2023/06/20
// Matchsticks Game
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchGame(long long N) {
        return (N % 5)? (N % 5): -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}

/* Sample Input:
5
1 4 5 15 48

Sample Output:
1
4
-1
-1
3

*/