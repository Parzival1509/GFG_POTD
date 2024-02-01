// GFG POTD 2023/09/11
// Lucky Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLucky(int n) {
        int count = 2;
        
        while(count <= n) {
            if(n % count == 0) return false;
                
            n -= n / count;
            ++count;
        }
        
        return true;
    }
};

signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        Solution obj;
        if(obj.isLucky(n))
            cout << "1\n";
        else cout << "0\n";
    }
    
}

/* Sample Input:
2
5 19

Sample Output:
0
1

*/