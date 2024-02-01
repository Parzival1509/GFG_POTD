// GFG POTD 2023/09/13
// Largest Possible Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLargest(int n, int s) {
        if((s == 0 && n > 1) || (s > 9 * n)) return "-1";
        
        string ans = "";
        while(n > 0) {
            int ch = s >= 9? 9: s;
            ans += ch + '0';
            n--;
            if(s >= 9) s -= 9;
            else s = 0;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, S;
        cin >> N >> S;
        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}

/* Sample Input:
4
2 9
3 20
9 82
4 0

Sample Output:
90
992
-1
-1

*/