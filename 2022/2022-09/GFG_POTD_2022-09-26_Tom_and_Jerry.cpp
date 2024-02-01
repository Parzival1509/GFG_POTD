// GFG POTD 2022/09/26
// Tom and Jerry
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numsGame(int n) {
        if(n%2==1) return 0;
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.numsGame(N) << endl;
    }
    return 0;
}

/* Sample Input
2
2 4

Sample Output
1
1

*/